#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

#include "stockType.h"
#include "stockListType.h"

//#define TEST

using namespace std;

//Seeks the input stream to the beginning of the file.
void rewind(ifstream&);

//Determines the number of rows in the file. Needed
//because of the required use of listType.
int determineRows(ifstream&);

//Inserts the stock listings from the file into the stockListType
//n - the number of rows to read.
//Function definition by Richard Stuart.
void readFileIntoList(ifstream&, stockListType&, int n);

//Prints the Header, called prior to printing the contents
//of the stockListType.
//Function definition by Richard Stuart.
void printHeader();

void printClosingAssets(stockListType&);
void printFooter();

int main()
{
	int numberOfRows;
	ifstream inFile;
	
	inFile.open("stocks.txt");
	if (!inFile)
	{
		cout << "File Not Found, Exiting." << endl;
		return EXIT_FAILURE;
	}

	numberOfRows = determineRows(inFile);
	rewind(inFile);
	stockListType stockList{ numberOfRows };

	readFileIntoList(inFile, stockList, numberOfRows);

	//Output sorted by stock symbol.
	printHeader();
	stockList.sortByStockSymbol();
	stockList.print();
	printClosingAssets(stockList);
	printFooter();

	cout << endl << endl;
	
	//Output sorted by gain/loss.
	printHeader();
	stockList.printByGainLoss();
	printClosingAssets(stockList);
	printFooter();

	system("pause");

	return EXIT_SUCCESS;
}

void rewind(ifstream& file)
{
	file.clear();
	file.seekg(0, ios::beg);
}


void printClosingAssets(stockListType& list)
{
	cout << "Closing Assets: " << "$" << fixed << setprecision(2) << list.totalValue() << endl;
}
void printFooter()
{
	string s = "_*_*_*_*_*_*_*_*";
	cout << s << s << s;
}
int determineRows(ifstream& stream)
{
	int numberOfRows = 0;
	string line;

	while (getline(stream, line))
		numberOfRows++;

	return numberOfRows;
}

//Function definition by Richard Stuart.
void readFileIntoList(ifstream& in, stockListType& list, int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		string symbol;
		double openPrice, closePrice, high, low, prevClose;
		long volume;

		in >> symbol >> openPrice >> closePrice >> high >> low >> prevClose >> volume;       //Worked here with symbol, and 2 #'s in file.
		stockType t{ symbol, openPrice, closePrice, high, low, prevClose, volume };
		list.insertAt(t, i);
	}
}

//Function definition by Richard Stuart.
void printHeader()
{
	cout << setw(40) << setfill('*') << "   First Investor's Heaven    " << setw(10) << "" << endl;
	cout << setw(40) << setfill('*') << "      Financial Report        " << setw(10) << "" << endl;
	cout << setfill(' ') << "Stock" << setw(20) << "Today" << setw(25) << "Previous" << setw(10) << "Percent" << endl;
	cout << "Symbol" << setw(9) << "Open" << setw(8) << "Close" << setw(8) << "High"
		<< setw(8) << "Low" << setw(8) << "Close" << setw(10) << "Gain" << setw(15) << "Volume" << endl;
	cout << setw(7) << setfill('-') << " " << setw(5) << setfill(' ') << "-" << setw(4) << setfill('-') << " "
		<< setw(3) << setfill(' ') << "-" << setw(5) << setfill('-') << " " << setw(4) << setfill(' ') << "-"
		<< setw(4) << setfill('-') << " " << setw(5) << setfill(' ') << "-" << setw(3) << setfill('-') << " "
		<< setw(3) << setfill(' ') << "-" << setw(6) << setfill('-') << " " << setw(5) << setfill(' ') << "-"
		<< setw(7) << setfill('-') << " " << setw(6) << setfill(' ') << "-" << setw(6) << setfill('-') << " ";

	cout << setfill(' ') << endl;
}

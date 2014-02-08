#include <iostream>
#include <memory>
#include <fstream>
#include <string>

#include "stockType.h"
#include "stockListType.h"

#define TEST

using namespace std;

//Seeks the input stream to the beginning of the file.
void rewind(ifstream&);

//Determines the number of rows in the file. Needed
//because of the required use of listType.
int determineRows(ifstream&);

//Inserts the stock listings from the file into the stockListType
//n - the number of rows to read.
void readFileIntoList(ifstream&, stockListType&, int n);

//Prints the heading, called prior to printing the contents
//of the stockListType.
void printHeading();

#ifdef TEST
stockType generateStock();
#endif

int main()
{
	int numberOfRows;
	ifstream inFile;
	
	inFile.open("stocks.txt");

#ifndef TEST
	numberOfRows = determineRows(inFile);
#else
	numberOfRows = 10;
#endif
	
	rewind(inFile);

	stockListType stockList{ numberOfRows };

	readFileIntoList(inFile, stockList, numberOfRows);

	stockList.sortByStockSymbol();

	printHeading();

	stockList.print();

	stockList.sortByGainLoss();

	printHeading();

	stockList.print();

	system("pause");
}

void rewind(ifstream& file)
{
	file.clear();
	file.seekg(0, ios::beg);
}

void printHeading()
{

}
int determineRows(ifstream& stream)
{
	int numberOfRows = 0;
	string line;

	while (getline(stream, line))
		numberOfRows++;

	return numberOfRows;
}

void readFileIntoList(ifstream& in, stockListType& list, int rows)
{
#ifdef TEST
	for (int i = 0; i < rows; ++i)
	{
		list.insertAt(generateStock(), i);
	}
#endif
	//Not implemented.
}

#ifdef TEST
stockType generateStock()
{
	static char l = 'A';
	static double c = 1.1;
	static double pc = 2.1;

	stockType t{ string{ l }, c, pc };

	l++;
	c++;
	pc++;

	return t;
}
#endif
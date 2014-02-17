#include "stockListType.h"
#include "stockType.h"
#include "listType.h"

using namespace std;

stockListType::stockListType(int maxSize) : listType<stockType>{ maxSize }
{
	vectorSize = 0;
}

void stockListType::sortByStockSymbol()
{

	listType<stockType>::sort();
}

//function definition by Jacob Mason
void stockListType::printByGainLoss()
{
	resizeVector(getLength());
	int sub = 0;
	//sort by GainLoss
	int prev_highest = -1;
	float highest = -999;
	int indice = 0;
	for (int i = 0; i < getLength(); i++)
	{
		for (int j = 0; j < getLength(); j++)
		{
			if ((list[j].getGainLoss() >= highest) && not_previous_index(j))
			{
				highest = list[j].getGainLoss();
				indice = j;
			}
		}
		if (not_previous_index(indice))
		{
			sortIndicesByGainLoss[sub] = indice;
			sub++;
		}
	}

	//printByGainLoss
	//needs the rest of the output too, but this is just to demonstrate
	//that it works
	for (int i = 0; i < getLength(); i++)
		cout << list[i].getSymbol() << " " << list[sortIndicesByGainLoss[i]].getGainLoss() << "%" << endl;
}
//function definition by Jacob Mason
bool stockListType::not_previous_index(int n)
{
	for (int i = 0; i < getLength(); i++)
	if (n == sortIndicesByGainLoss[i])
		return false;
	return true;
}

double stockListType::totalValue()
{
	double total = 0.0;
	for (int i = 0; i < getLength(); ++i)
	{
		total += list[i].getClose() * list[i].getShares();
	}
	return total;
}

//function definition jacob mason
//calling this will increase the number
//of objects the vectors can hold by n
//
//will also decrease number of objects 
//vectors can hold if n is negative
void stockListType::resizeVector(int n)
{
	vectorSize += n;
	sortIndicesByGainLoss.resize(vectorSize);
}



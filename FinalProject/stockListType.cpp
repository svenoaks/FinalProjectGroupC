//Function definition authors as noted.

#include "stockListType.h"
#include "stockType.h"
#include "listType.h"

using namespace std;

//Function definition by Steve Myers.
stockListType::stockListType(int maxSize) : listType<stockType>{ maxSize }
{}

//Function definition by Steve Myers.
void stockListType::sortByStockSymbol()
{
	listType<stockType>::sort();
}

//function definition by Jacob Mason
void stockListType::printByGainLoss()
{
	sortIndicesByGainLoss.resize(getLength());
	int sub = 0;
	//sort by GainLoss
	numberOfIndices = 0;
	double highest = -999;
	int indice = 0;

	for (int i = 0; i < getLength() + 1; i++)
	{
		highest = -999;
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
			numberOfIndices++;
			sortIndicesByGainLoss[sub] = indice;
			sub++;
		}
	}

	//printByGainLoss
	for (int i = 0; i < getLength(); i++)
		cout << list[sortIndicesByGainLoss[i]];
}

//function definition by Jacob Mason
bool stockListType::not_previous_index(int n)
{
	for (int i = 0; i < numberOfIndices; i++)
	if (n == sortIndicesByGainLoss[i])
		return false;
	return true;
}

//Function definition by Steve Myers.
double stockListType::totalValue()
{
	double total = 0.0;
	for (int i = 0; i < getLength(); ++i)
	{
		total += list[i].getClose() * list[i].getShares();
	}
	return total;
}




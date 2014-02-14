#include "stockListType.h"
#include "stockType.h"
#include "listType.h"

using namespace std;

stockListType::stockListType(int maxSize) : listType<stockType>{ maxSize }
{

}

void stockListType::sortByStockSymbol()
{
	
	listType<stockType>::sort();
}

void stockListType::printByGainLoss()
{

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



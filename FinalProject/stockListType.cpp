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

void stockListType::sortByGainLoss()
{
	;
}




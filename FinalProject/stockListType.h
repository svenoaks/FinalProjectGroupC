#ifndef stockListType_H
#define stockListType_H

#include "listType.h"
#include "stockType.h"
#include "listType.cpp"

using namespace std;

class stockListType : public listType<stockType>
{
private:
	unique_ptr<int[]> sortIndicesByGainLoss;

public:
	void sortByStockSymbol();
	void sortByGainLoss();

	stockListType(int maxSize);
};

#endif
#ifndef stockListType_H
#define stockListType_H

#include "listType.h"
#include "stockType.h"

using namespace std;

class stockListType : public listType<stockType>
{
private:
	unique_ptr<int[]> sortIndicesByGainLoss;

public:
	double totalValue();
	void sortByStockSymbol();
	void printByGainLoss();

	stockListType(int maxSize);
};

#endif
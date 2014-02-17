#ifndef stockListType_H
#define stockListType_H

#include "listType.h"
#include "stockType.h"
#include <vector>

using namespace std;

class stockListType : public listType<stockType>
{
private:
	vector<int> sortIndicesByGainLoss;
	int vectorSize;

public:
	double totalValue();
	void sortByStockSymbol();
	void resizeVector(int n);
	bool not_previous_index(int n);
	void printByGainLoss();
	stockListType(int maxSize);
};

#endif
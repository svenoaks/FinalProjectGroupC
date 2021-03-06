//Header file by Steve Myers except as noted.

#ifndef stockListType_H
#define stockListType_H

#include "listType.h"
#include "stockType.h"
#include <vector>

using namespace std;

class stockListType : public listType<stockType>
{
private:
	//private members by Jacob Mason.
	vector<int> sortIndicesByGainLoss;
	int numberOfIndices; //keep track of how many elements are actually in
						//sortIndicesByGainLoss, this is important
						//because vector initializes every int to zero
public:
	double totalValue();
	void sortByStockSymbol();
	void resizeVector(int n);
	bool not_previous_index(int n);
	void printByGainLoss();
	stockListType(int maxSize);
};

#endif
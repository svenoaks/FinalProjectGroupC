#include "stockType.h"

#include <iostream>
#include <cassert>

stockType::stockType(string symbol, double close, double previousClose,
	double open, double high, double low, long shares)
{
	this->symbol = symbol;
	this->close = close;
	this->previousClose = previousClose;
	this->open = open;
	this->high = high;
	this->low = low;
	this->shares = shares;

	//calculateGainLoss();
}

//Needed for temporary object in listType::sort().
stockType::stockType()
{}

bool stockType::operator<(const stockType& other) const
{
	assert(this->symbol.length() > 0 && other.symbol.length() > 0);

	//Not complete.
	return this->symbol[0] < other.symbol[0];
}
ostream& operator<<(ostream& out, const stockType& stock)
{
	//Needs to be revised.

	out << stock.symbol << " " << stock.close << " " << stock.previousClose << endl;

	return out;
}


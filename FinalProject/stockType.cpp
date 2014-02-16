#include "stockType.h"

#include <iostream>
#include <cassert>
#include <iomanip>

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

	calculateGainLoss();
}

//Function definition by Jacob Mason.
void stockType::calculateGainLoss()
{
	//formula (Price Sold - Purchase Price)/(Purchase Price) 
	gainLoss = (close - open) / open;
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

//Function definition by Richard Stuart.
ostream& operator<<(ostream& out, const stockType& stock)
{
	out << stock.symbol << " " << stock.open << " " << stock.close << " " << stock.high << " "
		<< stock.low << " " << stock.previousClose << " " << fixed << setprecision(2) 
		<< stock.gainLoss * 100.0 << "% " 
		<< stock.shares << endl;

	return out;
}

double stockType::getClose()
{
	return close;
}
long stockType::getShares()
{
	return shares;
}
void stockType::setShares(long shares)
{
	this->shares = shares;
}


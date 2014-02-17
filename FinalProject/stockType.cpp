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

string stockType::getSymbol()
{
	return symbol;
}
//Function definition by Jacob Mason.
void stockType::calculateGainLoss()
{
	//formula (Price Sold - Purchase Price)/(Purchase Price) 
	//((close - open)/(open)) * 100 
	this->gainLoss = (((this->close - this->open) / (this->open)) * 100);
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
double stockType::getOpen()
{
	return open;
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

double stockType::getGainLoss()
{
	return gainLoss;
}
//Function definition by Richard Stuart.
ostream& operator<<(ostream& out, const stockType& stock)
{
	out << fixed << showpoint << setprecision(2)
		<< setw(6) << stock.symbol << " " << setw(9) << stock.open << " "
		<< setw(7) << stock.close << " " << setw(7) << stock.high << " "
		<< setw(7) << stock.low << " " << setw(7) << stock.previousClose << " "
		<< setw(8) << stock.gainLoss << "% " << " "
		<< setw(12) << stock.shares << endl;

	return out;
}

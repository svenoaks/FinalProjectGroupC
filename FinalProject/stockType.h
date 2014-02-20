//Header file by Steve Myers.

#ifndef stockType_H
#define stockType_H

#include <string>

using namespace std;

class stockType
{
	friend ostream& operator<<(ostream&, const stockType&);
	friend istream& operator>>(istream&, stockType&);

private:
	string symbol;
	double close, previousClose;
	double open, high, low;
	double gainLoss;
	long shares;
	void calculateGainLoss();

public:
	void setSymbol(string);
	void setOpen(double);
	void setClose(double);
	void setHigh(double);
	void setLow(double);
	void setPreviousClose(double);
	void setShares(long);

	string getSymbol();
	double getOpen();
	double getClose();
	double getHigh();
	double getLow();
	double getPreviousClose();
	double getGainLoss();
	long getShares();

	void print() const;

	bool operator==(const stockType&) const;
	bool operator!=(const stockType&) const;
	bool operator<(const stockType&) const;
	bool operator<=(const stockType&) const;
	bool operator>(const stockType&) const;
	bool operator>=(const stockType&) const;

	//The symbol, closing price and previous closing price is the
	//minimum amount of information required to properly construct a 
	//stockType object. calculateGainLoss() should be invoked in the
	//constructor. 

	stockType(string symbol, double close, double previousClose,
		double open = 0, double high = 0, double low = 0, long shares = 0);

	//Needed for temporary object creation in listType::sort()
	stockType();
};

#endif
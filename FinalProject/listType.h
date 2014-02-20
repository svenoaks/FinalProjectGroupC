//Header file by Steve Myers.

#ifndef listType_H
#define listType_H

#include <iostream>
#include <cassert>
#include <memory>

using namespace std;

template <class E>
class listType
{
protected:
	int maxSize;
	int length;
	unique_ptr<E[]> list;

public:
	bool isEmpty() const;
	bool isFull() const;
	int getLength() const;
	int getMaxSize() const;
	void sort();
	void print() const;
	void insertAt(const E& item, int position);

	listType(int listSize = 50);
};

#endif
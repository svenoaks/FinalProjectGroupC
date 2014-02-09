#include <memory>
#include <type_traits>
#include <utility>

#include "listType.h"
#include "stockType.h"

//#define GCC

using namespace std;

#ifdef GCC
template <class T, class ...Args>
typename std::enable_if
<
!std::is_array<T>::value,
std::unique_ptr<T>
>::type
make_unique(Args&& ...args)
{
	return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template <class T>
typename std::enable_if
<
std::is_array<T>::value,
std::unique_ptr<T>
>::type
make_unique(std::size_t n)
{
	typedef typename std::remove_extent<T>::type RT;
	return std::unique_ptr<T>(new RT[n]);
}
#endif


template <class E>
bool listType<E>::isEmpty() const
{
	return length == 0;
}

template <class E>
bool listType<E>::isFull() const
{
	return length == maxSize;
}

template <class E>
int listType<E>::getLength() const
{
	return length;
}

template <class E>
int listType<E>::getMaxSize() const
{
	return maxSize;
}

template <class E>
listType<E>::listType(int listSize)
{
	maxSize = listSize;
	length = 0;
	list = make_unique<E[]>(maxSize);
}

template<class E>
void listType<E>::sort()
{
	int i, j;
	int min;
	E temp;

	for (i = 0; i < length; ++i)
	{
		min = i;
		for (j = i + 1; j < length; ++j)
		if (list[j] < list[min])
			min = j;

		temp = list[i];
		list[i] = list[min];
		list[min] = temp;
	}
}

template <class E>
void listType<E>::print() const
{
	int i;
	for (i = 0; i < length; ++i)
		cout << list[i];
	cout << endl;
}

template <class E>
void listType<E>::insertAt(const E& item, int position)
{
	assert(position >= 0 && position < maxSize);
	list[position] = item;
	length++;
}

template class listType<stockType>;
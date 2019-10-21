#include <iostream>

#include "Vector.h"

extern void tst();

int main()
{
	using namespace cc;
	
	Vector<int> vec(30, 3);

	std::cout << vec._data[3];

	tst();

	return 0;
}

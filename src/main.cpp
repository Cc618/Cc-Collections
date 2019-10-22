#include <iostream>

#include "Array.h"

int main()
{
	using namespace cc;
	
	Array<int> a(3, 2);

	a[2] = 9;

	a.print();

	a.resize(16);
	a.print();

	a.resize(1);
	a.print();

	a.resize(0);
	a.print();

	a.resize(10);
	a.print();

	return 0;
}

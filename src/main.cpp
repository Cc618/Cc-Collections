#include <iostream>

#include "Array.h"

int main()
{
	using namespace cc;
	
	Array<int> a(3, 2);

	a[10] = 9;

	std::cout << a[1] << '\n';

	a.print();

	return 0;
}

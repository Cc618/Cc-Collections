#include <iostream>

#include "Array.h"

int main()
{
	using namespace cc;
	
	Array<int> a(3);

	a.set(1, 42);

	a.print();

	return 0;
}

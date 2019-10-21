#include <iostream>

#include "Vector.h"

int main()
{
	using namespace cc;
	
	Vector<int> v(3);

	v.set(1, 42);

	v.print();

	return 0;
}

#include <iostream>

#include "Vector.h"


int main()
{
	using namespace cc;
	
	Vector<int> vec(30, 3);

	std::cout << vec._data[3];

	return 0;
}

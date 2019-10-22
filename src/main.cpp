#include <iostream>

#include "Array.h"

int main()
{
	using namespace cc;
	
	Array<int> a(3, -1);
	// a = {-1, -1, -1}
	
	a.set(1, 42);
	// a = {-1, 42, -1}

	auto b = a;
	// b = {-1, 42, -1}

	b.set(2, 3);
	// b = {-1, 42, 3}

	a.set(0, 116);
	// b = {116, 42, -1}

	std::cout << "a: " << a << '\n';
	std::cout << "b: " << b << '\n';

	return 0;
}

// TODO: std::ostream& operator<<(std::ostream& stream, const Array<T>& ARRAY);

#pragma once

#include <inttypes.h>

namespace cc
{
	template <typename T>
	class Vector
	{
	public:
		// Data is null
		Vector();
		// Init the array with COUNT elements (default value)
		Vector(const size_t COUNT);
		// Init the array with COUNT elements of value VALUE
		Vector(const size_t COUNT, const T VALUE);

		~Vector();

	private:
		// The raw data
		T **_data;

		// Elements amount
		size_t _count;
	};

	//// Constructors ////
	template <typename T>
	Vector<T>::Vector()
		: _data(nullptr), _count(0)
	{}

	template <typename T>
	Vector<T>::Vector(const size_t COUNT)
		: _count(COUNT)
	{
		// Allocate
		_data = new T[COUNT];
	}

	template <typename T>
	Vector<T>::Vector(const size_t COUNT, const T VALUE)
		: _count(COUNT)
	{
		// Allocate
		_data = new T[COUNT];

		// Set the data
		for (size_t i = 0; i < COUNT; ++i)
			data[COUNT] = VALUE;
	}

	//// Methods ////

}

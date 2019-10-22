#pragma once

#include <inttypes.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cassert>

namespace cc
{
	template <typename T>
	class Array
	{
	public:
		//// Constructors ////
		// Data is null
		Array();
		// Copy
		Array(const Array& OTHER);
		// Inits the array with COUNT elements (default value)
		explicit Array(const size_t COUNT);
		// Inits the array with COUNT elements of value VALUE
		Array(const size_t COUNT, const T& VALUE);

		~Array();

	public:
		//// Getters ////
		// Returns the number of items
		inline size_t getCount() const
		{
			return _count;
		}

		// Returns the raw data
		inline const T *getData() const
		{
			return _data;
		}

		// Returns the string version of the array (like in print but without the new line)
		std::string toString() const;

		// Prints the data
		void print() const;

	public:
		//// Operators ////
		// Set
		Array &operator=(const Array& OTHER);
		
		// At
		T &operator[](const size_t i);
		T operator[](const size_t i) const;

	private:
		//// Procedures ////
		// Copies an array of the same size into this array
		// !!! The size of the other array is not checked
		// !!! The size of this array is not updated
		void copy(const Array& OTHER);

	private:
		//// Attributes ////
		// The raw data
		T *_data;

		// Elements amount
		size_t _count;
	};


	//// Constructors ////
	template <typename T>
	Array<T>::Array()
		: _data(nullptr), _count(0)
	{}

	template <typename T>
	Array<T>::Array(const Array& OTHER)
		: _count(OTHER._count)
	{
		copy(OTHER);
	}

	template <typename T>
	Array<T>::Array(const size_t COUNT)
		: _count(COUNT)
	{
		// Allocate
		_data = new T[COUNT];
	}

	template <typename T>
	Array<T>::Array(const size_t COUNT, const T& VALUE)
		: _count(COUNT)
	{
		// Allocate
		_data = new T[COUNT];

		// Set the data
		for (size_t i = 0; i < COUNT; ++i)
			_data[i] = VALUE;
	}

	template <typename T>
	Array<T>::~Array()
	{
		// Free
		delete[] _data;
	}


	//// Setters ////


	//// Getters ////
	template <typename T>
	std::string Array<T>::toString() const
	{
		// Empty array
		if (_count == 0)
			return "[]";

		// Use string stream for optimization
		std::ostringstream out;
		out << "{" << std::to_string(_data[0]);

		// Add comma separated numbers
		for (size_t i = 1; i < _count; ++i)
			out << ", " << std::to_string(_data[i]);
		
		out << "}";

		return out.str();
	}

	template <typename T>
	void Array<T>::print() const
	{
		std::cout << toString() << '\n';
	}


	//// Operators ////
	template <typename T>
	Array<T> &Array<T>::operator=(const Array& OTHER)
	{
		// Free memory
		delete[] _data;

		// Copy
		_count = OTHER._count;
		copy(OTHER);

		return *this;
	}

	template <typename T>
	T &Array<T>::operator[](const size_t i)
	{
		// i is beyond limits
		assert(i < _count && "The index is beyond limits");

		return _data[i];
	}

	template <typename T>
	T Array<T>::operator[](const size_t i) const
	{
		// i is beyond limits
		assert(i < _count && "The index is beyond limits");

		return _data[i];
	}


	//// Procedures ////
	template <typename T>
	void Array<T>::copy(const Array& OTHER)
	{
		// Reallocate data
		_data = new T[_count];

		// Copy data
		std::memcpy(_data, OTHER._data, sizeof(T) * _count);
	}


	//// Functions ////
	// aucun opérateur "<<" ne correspond à ces opérandes -- les types d'opérandes sont : std::basic_ostream<char, std::char_traits<char>> << cc::Array<int>
	template <typename T>
	std::ostream& operator<<(std::ostream& stream, const Array<T>& ARRAY)
	{
		stream << ARRAY.toString();

		return stream;
	}
}

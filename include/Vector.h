#pragma once

#include <inttypes.h>
#include <iostream>
#include <string>
#include <sstream>

namespace cc
{
	template <typename T>
	class Vector
	{
	public:
		//// Constructors ////
		// Data is null
		Vector();
		// Inits the array with COUNT elements (default value)
		explicit Vector(const size_t COUNT);
		// Inits the array with COUNT elements of value VALUE
		Vector(const size_t COUNT, const T& VALUE);

		~Vector();

	public:
		//// Setters ////
		// !!! Temporary method
		// TODO : Overload operators + memory safe
		void set(size_t index, const T& VALUE)
		{
			_data[index] = VALUE;
		}

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

		// Returns the string version of the vector (like in print but without the new line)
		std::string toString() const;

		// Prints the data
		void print() const;

	private:
		//// Attributes ////
		// The raw data
		T *_data;

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
	Vector<T>::Vector(const size_t COUNT, const T& VALUE)
		: _count(COUNT)
	{
		// Allocate
		_data = new T[COUNT];

		// Set the data
		for (size_t i = 0; i < COUNT; ++i)
			_data[i] = VALUE;
	}

	template <typename T>
	Vector<T>::~Vector()
	{
		// Free
		delete[] _data;
	}

	//// Getters ////
	template <typename T>
	std::string Vector<T>::toString() const
	{
		// Empty vector
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
	void Vector<T>::print() const
	{
		std::cout << toString() << '\n';
	}
}

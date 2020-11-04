#include "Array.h"
#include <cassert>
#include <ctime>
#include <stdexcept>
#include <algorithm>
#include <iostream>
/*
int Array::getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
	
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
void Array::shuffle()
{
	for (int index = 0; index < m_length; index++)
	{
		int swapIndex = getRandomNumber(0, m_length - 1);
		std::swap(m_array[index], m_array[swapIndex]);
	}
}
*/
Array::Array() : m_length(0), m_array(nullptr) {};
Array::Array(int length): m_length(length)
{
	assert(length >= 0);

	if (length > 0)
	{
		m_array = new int[length];
		for (int i = 0; i < length; i++)
			m_array[i] = 0;
	}
	else m_array = nullptr;
}

Array::Array(int length, int* arr): m_length(length)
{
	assert(length >= 0);

	if (length > 0)
	{
		m_array = new int[length];
		for (int i = 0; i < length; i++)
			m_array[i] = arr[i];
	}
	else m_array = nullptr;
}

Array::~Array()
{
	//delete[] m_array;
}


void Array::initialize()
{
	for (int i = 0; i < m_length; i++)
		m_array[i] = 0;
}
int Array::getLength()const
{
	return m_length;
}
int* Array::getArray()const
{
	return m_array;
}

int Array::getElement(int index)
{
	assert(index < m_length && index >= 0);
		return m_array[index];
}

Array& Array::operator=(const Array& arr)
{
	if (this == &arr)
		return *this;
	if (m_array) delete[] m_array;

	m_length = arr.m_length;

	m_array = new int[m_length];
	for (int i = 0; i < m_length; i++)
		m_array[i] = arr.m_array[i];

	return *this;
}
const  Array Array::operator+(const Array& arr)const
{
	assert(m_length == arr.m_length);

	Array result = *this;

	for (int i = 0; i < m_length; i++)
	{
		result.getArray()[i] += arr.getArray()[i];
	}
	return result;
}
const  Array Array::operator-(const Array& arr)const
{
	assert(m_length == arr.m_length);

	Array result = *this;

	for (int i = 0; i < m_length; i++)
	{
		result.getArray()[i] -= arr.m_array[i];
	}
	return result;
}
const  Array Array::operator*(const Array& arr)const
{
	assert(m_length == arr.m_length);

	Array result = *this;

	for (int i = 0; i < m_length; i++)
	{
		result.getArray()[i] *= arr.m_array[i];
	}
	return result;
}

void Array::show()const
{
	for (int i = 0; i < getLength(); i++)
		std::cout << getArray()[i] << " ";
	std::cout << "\n";
}
#include "DinamicArray.h"
#include <iostream>
#include <cassert>
#include <ctime>
#include <stdexcept>
#include <algorithm>

DinamicArray::DinamicArray():m_length(0), m_array(nullptr){}

DinamicArray::DinamicArray(int length) : m_length(length)
{
	assert(length >= 0);
	
	if (length > 0)
		m_array = new int[length];
	else
		m_array = nullptr;
}

DinamicArray::~DinamicArray() { delete[] m_array; };

int DinamicArray::getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // используем static, так как это значение нужно вычислить единожды
	// Равномерно распределяем вычисление значения из нашего диапазона
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void DinamicArray::initRandom()
{
	srand(time(NULL));
	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = rand() % 10;
	}
}

void DinamicArray::shuffle()
{
	for (int index = 0; index < m_length; index++)
	{
		int swapIndex = getRandomNumber(0, m_length-1);
		std::swap(m_array[index], m_array[swapIndex]);
	}
}

int DinamicArray::getDiffCount()
{
	int diffCount = 0;
	int i, j;
	for (i = 0; i < m_length; i++)
	{
		for (j = 0; j < i && m_array[i] != m_array[j]; ++j);
		// j не продвинулось -> с каким-то элементом было равенство (элемент совпал с посчитанным) -> выходим из цикла по j 
		diffCount += j == i;
	}
	return diffCount;
}

void DinamicArray::print()
{
	for (int i = 0; i < m_length; i++)
	{
		std::cout << m_array[i] << " ";
	}
	std::cout << "\n";
}
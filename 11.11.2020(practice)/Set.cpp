#include "Set.h"
#include <cassert>
#include <iostream>
#include <algorithm>

Set::Set(): m_n(0), m_vec(nullptr), m_sorted(false)
{

}
bool Set::IsInSet(int value)
{
	for (int i = 0; i < m_n; i++)
		if (m_vec[i] == value) return true;
	return false;
}

Set::Set(int num): m_n(num), m_sorted(false)
{
	assert(num >= 0);

	if (num > 0)
	{
		m_vec = new int[num];
	}
	else
		m_vec = nullptr;
}
/*
Set::Set(int num, int* vec): m_n(num)
{
	assert(num >= 0);

	if (num > 0)
	{
		m_vec = new int[num];
		// suppose the sets is 
		for (int i=0; i < m_n; i++)
			m_vec[i] = 
	}

}
*/

int Set::GetSize()
{
	return m_n;
}

void Set::Add(int value)
{
	if (IsEmpty())
	{
		m_n = 1;
		m_vec = new int[1];
		m_vec[0] = value;
		std::cout << value << " is added in set.\n";
	}
	else
	{
		if (IsInSet(value))
		{
			std::cout << value << " already in set. \n";
			return;
		}
		else
		{

			int* tmp = new int[m_n + 1];
			for (int i = 0; i < m_n; i++)
			{
				tmp[i] = m_vec[i];
			}
			tmp[m_n] = value;

			delete[] m_vec;
			m_vec = new int[++m_n];
			for (int i = 0; i < m_n; i++)
				m_vec[i] = tmp[i];

			delete[] tmp;
			std::cout << value << " is added in set.\n";
		}
	}
}

void Set::Del(int value)
{
	if (IsEmpty())
	{
		std::cout << "The set is empty.\n";
			return;
	}
	else
	{
		if (!IsInSet(value))
		{
			std::cout << "There is no " << value << " to be deleted.\n";
			return;
		}
		else
		{
			int* tmp = new int[m_n - 1];
			for (int i = 0; i < m_n; i++)
			{
				if (m_vec[i] != value)
				{
					tmp[i] = m_vec[i];
				}
			}
			delete[] m_vec;

			m_vec = new int[--m_n];
			for (int i = 0; i < m_n; i++)
			{
				m_vec[i] = tmp[i];
			}
			delete[] tmp;
			std::cout << value << " is deleted from set.\n";
		}
	}
}

bool Set::IsEmpty()
{
	return m_n == 0;
}

int Set::GetMax()
{
	if (IsEmpty())
	{
		std::cout << "The set is empty. As max element is returned zero.\n";
		return 0;
	}
	else
	{
		if (IsSorted())
		{
			return m_vec[m_n - 1];
		}
		else
		{
			int max = m_vec[0];
			for (int i = 0; i < m_n; i++)
				max = (m_vec[i] > max) ? m_vec[i] : max;
			return max;
		}
	}
}

bool Set::IsSorted()
{
	return m_sorted;
}
void Set::Sort()
{
	for (int i = 0; i < m_n - 1; i++)
		for (int j = i; j < m_n; j++)
			if (m_vec[i] > m_vec[j])
				std::swap(m_vec[i], m_vec[j]);
	m_sorted = true;
}

void Set::PrintToFilePrimes(std::ofstream & out)
{
	out << "Prime numbers from set:\n";
	int i, j;
	int max = (*this).GetMax();
	
	int* sieve = new int[max+1];
	for (i = 0; i < max+1; i++)
		sieve[i] = 0;
	for (i = 2; i * i < max+1; ++i)
		for (j = i*i; j < max+1; j+=i)
			sieve[j] = 1; //если индекс j - составное число, то sieve[j] = 1, иначе sieve[j]=0
	
	for (i = 0; i < m_n; i++)
		if ((!sieve[m_vec[i]]) && (m_vec[i] != 1) && (m_vec[i] != 0))
			out << m_vec[i] << "\t";

	out << "\n";
	delete[] sieve;
}


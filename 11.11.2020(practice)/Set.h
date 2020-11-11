#pragma once
#include <fstream>
class Set
{
	int m_n;
	int* m_vec;
	bool m_sorted;

public:
	Set();
	//Set(int, int*);
	Set(int);

	int GetSize();

	bool IsInSet(int);

	bool IsEmpty();

	bool IsSorted();

	void Add(int);
	void Del(int);

	int GetMax();

	void Sort();

	void PrintToFilePrimes(std::ofstream&);
};


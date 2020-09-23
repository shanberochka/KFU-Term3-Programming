#include "FixRowArray.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream> 

FixRowArray::FixRowArray()
	:m_rowsNum(0),m_rowsLen(0)
{

};
FixRowArray::FixRowArray(int num, int len=0)
	: m_rowsNum(num), m_rowsLen(len)
{
	m_array.resize(m_rowsNum);
	for (int i = 0; i < m_rowsNum; i++)
		m_array[i].resize(m_rowsLen);
};
FixRowArray::~FixRowArray() {};

void FixRowArray::init()
{
	std::cout << "Initializing\n";
	for (int i = 0; i < m_rowsNum; i++)
	{
		std::cout << "#" << i + 1 << ": ";
		for (int j = 0; j < m_rowsLen; j++)// вводить не всю длину!!
		{
			std::cin >> m_array[i][j];
		}
		std::cin.ignore(32767, '\n');
	}
}
int FixRowArray::getRowsNum()
{
	return m_rowsNum;
}
std::vector<std::vector<int>> FixRowArray::getArray()
{
	return m_array;
}

std::vector<int> FixRowArray::getRow(int rowNum)
{
	return m_array[rowNum - 1];
}

int FixRowArray::getElement(int rowNum, int elementNum)
{
	return m_array[rowNum - 1][elementNum-1];
}

std::ostream& operator<<(std::ostream& out, const FixRowArray& text)
{
	
	return out;
}

std::ostream& operator<<(std::ostream& out, const std::vector<int>& line)
{
	out << line;
	return out;
}

void FixRowArray::print()
{
	for (int i = 0; i < m_rowsNum; i++)
	{
		std::cout << "#" << i + 1 << ": ";
		for (int j = 0; j < m_rowsLen; j++)
			std::cout << std::setw(5) << m_array[i][j];
		std::cout << "\n";
 	}
}

void FixRowArray::printLine(int num)
{
	for (int i = 0; i < m_rowsLen; i++)
		std::cout << std::setw(5) << m_array[num - 1][i];
	std::cout <<"\n";
}

void FixRowArray::merge(int row1, int row2)
{
	//push_back
	m_array.resize(++m_rowsNum);
	m_array[m_rowsNum - 1].resize(m_rowsLen);
	std::string s;
	for (int i = 0; i < m_rowsLen; i++)
	{
		s = std::to_string(m_array[row1-1][i]) + std::to_string(m_array[row2-1][i]);
		std::stringstream el(s);
		//std::cout << s << "\t"; std::stoi(s); std::cout << typeid(s).name();
		el >> m_array[m_rowsLen][i];
	}
	std::cout << "\n";
}

void FixRowArray::excludeMerge(int row1, int row2)
{
	//pop
	std::vector<int> line1 = m_array[row1];
	std::vector<int> line2 = m_array[row2];

	std::vector<int> result;
	line1.insert(line1.end(), line2.begin(), line2.end());
	result = line1;
	//sort(result.begin(), result.end());

	std::vector<int> duplicates;

	//написать л€мбду
	for (int i = 1; i < result.size(); i++)
		if (result[i - 1] == result[i])
			duplicates.push_back(result[i]);
	sort(duplicates.begin(), duplicates.end());

	result.erase(remove_if(begin(result), end(result),
		[&](auto x) {return binary_search(begin(duplicates), end(duplicates), x); }), end(result));

	// кол-во строк уменьшить(удалить старые, добавить новую)
	m_array.erase(m_array.begin()+row1 - 1);
	m_array.erase(m_array.begin() + row2 - 1);// удалаетс€ перва€ - индексы мен€ютс€

	m_array.push_back(result);
	m_rowsNum--;
}
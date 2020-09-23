#pragma once
#include <vector>
#include <iostream>
class FixRowArray
{
private:
	//int**m_array,*m_firstRow, m_rowsNum, m_rowsLen;
	int m_rowsNum,const m_rowsLen;
	std::vector<std::vector<int>> m_array;
public:
	FixRowArray();
	FixRowArray(int, int);
	~FixRowArray();

	int getRowsNum();
	std::vector<std::vector<int>> getArray();
	std::vector<int> getRow(int);
	int getElement(int, int);
	void init();

	friend std::ostream& operator<<(std::ostream&, const FixRowArray&);
	friend std::ostream& operator<<(std::ostream&, const std::vector<int>&);
	//перегрузить для объетов класса и строк 
	void print();
	void printLine(int);

	void merge(int, int);

	void excludeMerge(int, int);//кол-во строк уменьшить(удалить старые, добавить новую)
};


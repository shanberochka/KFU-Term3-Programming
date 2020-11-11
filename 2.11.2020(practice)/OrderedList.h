#pragma once

#include "List.h"
#include "List.cpp"
#include <fstream>

template <typename T>
class OrderedList :
	public List<T>
{

public:
	OrderedList();
	~OrderedList();

	OrderedList operator=(OrderedList);
	OrderedList operator+(OrderedList& second);
	OrderedList operator^(OrderedList& second);
	void doOrdered();

	void getFromFile(std::ifstream&);

	void printToFile(std::ofstream&);

	void addElement(T);
};


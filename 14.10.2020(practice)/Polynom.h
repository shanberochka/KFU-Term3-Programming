#pragma once
#include "Array.h"
#include <iostream>

class Polynom :
	public Array
{
public:
	
	const Polynom operator*(const Polynom&)const;
	const Polynom operator+(const Polynom&)const;
	const Polynom operator-(const Polynom&)const;
	friend std::ostream& operator<<(std::ostream&, const Polynom&);
	Polynom();
	Polynom(int);
	Polynom(int, int*);

	int getDegree()const;
	int* getCoeffs()const;
	virtual void show()const;
};


#pragma once
#include "Polynom.h"
class Matrix
{
private:
	int m_length;

	Polynom* m_p;
public:
	Matrix();
	Matrix(int);
	Matrix(int, Polynom*);

	int getLength()const;
	Polynom* getPolynom()const;
	Matrix& operator=(const Matrix&);
	const Matrix operator+(const Matrix&)const;

	void show()const;
};


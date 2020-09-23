#pragma once
#include <iostream>
class Polynomial
{
private:
	int m_degree;
	double* m_coeffs;

public:
	Polynomial();
	Polynomial(int);
	~Polynomial();

	int getDegree()const;
	double* getCoeffs()const;

	void initByZeros();
	void init();
	double getResult(double);

	Polynomial& operator=(const Polynomial&);
	Polynomial operator+(const Polynomial&)const;
	Polynomial operator-(const Polynomial&)const;
	Polynomial operator*(const Polynomial&)const;

	friend std::ostream& operator<<(std::ostream&, const Polynomial&);
	void print();
};


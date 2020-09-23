#include "Polynomial.h"
#include <cassert>

void Polynomial::initByZeros()
{
	for (int i = 0; i < m_degree+1; i++)
		m_coeffs[i] = 0.0;
}
Polynomial::Polynomial() :m_degree(0), m_coeffs(nullptr){}
Polynomial::Polynomial(int degree) : m_degree(degree)
{
	assert(m_degree >= 0);

	if (m_degree > 0)
	{
		m_coeffs = new double[m_degree+1];
		initByZeros();
	}
	else
		m_coeffs = nullptr;
}
Polynomial::~Polynomial()
{ 
	//delete[] m_coeffs;
}

int Polynomial::getDegree()const
{
	return m_degree;
}

double* Polynomial::getCoeffs()const
{
	return m_coeffs;
}

void Polynomial::init()
{
	double coef;
	std::cout << "\nEnter polynomial coefficients:\n";
	for (int i = 0; i < m_degree + 1; i++)
	{
		std::cout << "x^" << i << ": ";
		std::cin >> coef;
		m_coeffs[i] = coef;
	}
}

double Polynomial::getResult(double x)
{
	double result = 0;
	for (int i = m_degree; i >= 0; i--)
		result = m_coeffs[i] + (x * result);
	return result;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& p)
{
	int degree = p.getDegree();
	for (int i = 0; i < degree; i++)
		//if (p.getCoeffs()[i] != 0.0)
	{
		 out << p.getCoeffs()[i] << "x^" << i << " + ";
	}

	out << p.getCoeffs()[degree] << "x^" << degree << "\n";
	return out;
}

Polynomial& Polynomial::operator=(const Polynomial& p)
{
	return *this;
}

Polynomial Polynomial::operator+(const Polynomial& secondPoly)const
{
	// вставить функцию сокращения длины массива коэф-в (как сокращение дроби)
	int i;
	Polynomial fisrtPoly = *this;
	int fd = fisrtPoly.m_degree, sd = secondPoly.m_degree;

	int degree = fd > sd ? fd : sd;
	Polynomial c(degree);
	
	for (i = 0; i < fd+1; i++) c.m_coeffs[i] += fisrtPoly.m_coeffs[i];
	for (i = 0; i < sd+1; i++) c.m_coeffs[i] += secondPoly.m_coeffs[i];
	return c;
}

Polynomial Polynomial::operator-(const Polynomial& secondPoly)const
{
	// вставить функцию сокращения длины массива коэф-в (как сокращение дроби)
	int i;
	Polynomial fisrtPoly = *this;
	int fd = fisrtPoly.m_degree, sd = secondPoly.m_degree;

	int degree = fd > sd ? fd : sd;
	Polynomial c(degree);

	for (i = 0; i < fd+1; i++) c.m_coeffs[i] += fisrtPoly.m_coeffs[i];
	for (i = 0; i < sd+1; i++) c.m_coeffs[i] -= secondPoly.m_coeffs[i];
	return c;
}

Polynomial Polynomial::operator*(const Polynomial& secondPoly)const
{
	// вставить функцию сокращения длины массива коэф-в (как сокращение дроби)
	int i, j;
	Polynomial fisrtPoly = *this;
	int fd = fisrtPoly.m_degree, sd = secondPoly.m_degree;

	int degree = fd + sd;
	Polynomial c(degree);

	for (i = 0; i < fd + 1; i++)
		for (j = 0; j < sd + 1; j++)
			c.m_coeffs[i + j] += (fisrtPoly.m_coeffs[i] * secondPoly.m_coeffs[j]);
	return c;
}

void Polynomial::print()
{
	std::cout << "Info: \n";
	std::cout << "Polynomial degree: " << m_degree << "\n";
	for (int i = 0; i < m_degree+1; i++)
		if (m_coeffs[i] != 0)
		{
			std::cout << m_coeffs[i] << "x^" << i << " ";
		}
	std::cout << "\n";
}
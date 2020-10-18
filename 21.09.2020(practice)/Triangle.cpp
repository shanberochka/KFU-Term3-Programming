#include "Triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle():m_a(0), m_b(0), m_c(0){}
Triangle::Triangle(int a, int b, int c)
{
	if ((a + b > c) && (a + c > b) && (b + c > a))
	{
		m_a = a;
		m_b = b;
		m_c = c;
	}
	else std::cout << "Such triangle can't exist!\n";
}
Triangle::~Triangle(){}

int Triangle::getA() { return m_a; }
int Triangle::getB() { return m_b; }
int Triangle::getC() { return m_c; }

bool Triangle::checkCorrect(int a, int b, int c)
{
	return ((a + b > c) && (a + c > b) && (b + c > a));
}

void Triangle::setA(int a)
{
	if (checkCorrect(a, m_b, m_c))
		m_a = a;
	else
		std::cout << "Such triangle can't exist!\n";
}
void Triangle::setB(int b)
{
	if (checkCorrect(m_a, b, m_c))
		m_b = b;
	else
		std::cout << "Such triangle can't exist!\n";
}

void Triangle::setC(int c)
{
	if (checkCorrect(m_a, m_b, c))
		m_c = c;
	else 
		std::cout << "Such triangle can't exist!\n";
}

void Triangle::show()
{
	std::cout << "This triangle has: \n";
	std::cout << "a=" << m_a << "; \nb=" << m_b << "; \nc=" << m_c << "\n";
}

//void Triangle::changeA()
//void Triangle::changeB()
//void Triangle::changeC()

int Triangle::getPerimeter()
{
	return (m_a + m_b + m_c);
}
double Triangle::getSquare()
{
	int p = 0.5 * (m_a + m_b + m_c);
	return sqrt(p*(p-m_a)*(p-m_b)*(p-m_c))
}

double Triangle::getInscibedCircleRadius()
double Triangle::getCircumCircleRadius()
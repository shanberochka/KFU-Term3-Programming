#include "Polynom.h"
#include <cassert>

Polynom::Polynom(): Array() {};

Polynom::Polynom(int degree): Array(degree+1) {};

Polynom::Polynom(int degree, int* arr) : Array(degree+1, arr) {};

int Polynom::getDegree()const
{
	return getLength()-1;
}
int* Polynom::getCoeffs()const
{
	return getArray();
}
const Polynom Polynom::operator*(const Polynom& secondPoly)const
{
	int i, j;
	Polynom fisrtPoly = *this;
	int fd = fisrtPoly.getDegree();
	int sd = secondPoly.getDegree();

	int degree = fd + sd;
	Polynom c(degree);
	c.initialize();

	for (i = 0; i < fd + 1; i++)
		for (j = 0; j < sd + 1; j++)
		{
			//std::cout << fisrtPoly.getCoeffs()[i] << "\t" << secondPoly.getCoeffs()[j] << "\n";
			c.getCoeffs()[i + j] += (fisrtPoly.getCoeffs()[i] * secondPoly.getCoeffs()[j]);
		}
	return c;
}

const Polynom Polynom::operator+(const Polynom& secondPoly)const
{
	int i;
	Polynom fisrtPoly = *this;
	int fd = fisrtPoly.getDegree();
	int sd = secondPoly.getDegree();

	int degree = fd > sd ? fd : sd;
	Polynom c(degree);
	c.initialize();

	for (i = 0; i < fd + 1; i++) c.getCoeffs()[i] += fisrtPoly.getCoeffs()[i];
	for (i = 0; i < sd + 1; i++) c.getCoeffs()[i] += secondPoly.getCoeffs()[i];

	return c;
}
const Polynom Polynom::operator-(const Polynom& secondPoly)const
{
	int i;
	Polynom fisrtPoly = *this;
	int fd = fisrtPoly.getDegree();
	int sd = secondPoly.getDegree();

	int degree = fd > sd ? fd : sd;
	Polynom c(degree);
	c.initialize();

	for (i = 0; i < fd + 1; i++) c.getCoeffs()[i] += fisrtPoly.getCoeffs()[i];
	for (i = 0; i < sd + 1; i++) c.getCoeffs()[i] -= secondPoly.getCoeffs()[i];

	return c;
}
void Polynom::show()const
{
	int degree = getDegree();

	assert(degree >= 0);

	for (int i = 0; i < degree; i++)
	{
		std::cout << getCoeffs()[i] << "x^" << i << " + ";
	}
	std::cout << getCoeffs()[degree] << "x^" << degree << "\n";
}

std::ostream& operator<<(std::ostream& out, const Polynom& p)
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

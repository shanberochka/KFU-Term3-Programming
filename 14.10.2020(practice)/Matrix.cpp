#include "Matrix.h"
#include <cassert>

Matrix::Matrix():m_length(0),m_p(nullptr){};

Matrix::Matrix(int length): m_length(length)
{
	assert(length >= 0);

	if (length > 0)
	{
		m_p = new Polynom[length];
		for (int i = 0; i < length; i++)
			m_p[i] = Polynom(0);
	}
	else m_p = nullptr;
}

Matrix::Matrix(int length, Polynom* p): m_length(length)
{
	assert(length >= 0);

	if (length > 0)
	{
		m_p = new Polynom[length];
		for (int i = 0; i < length; i++)
		{
			m_p[i] = p[i];
			std::cout << m_p[i] << "\n";
		}
			
	}
	else m_p = nullptr;
};

int Matrix::getLength()const
{
	return m_length;
}
Polynom* Matrix::getPolynom()const
{
	return m_p;
}

Matrix& Matrix::operator=(const Matrix& arr)
{
	if (this == &arr)
		return *this;
	if (m_p) delete[] m_p;

	m_length = arr.m_length;

	m_p = new Polynom[m_length];
	for (int i = 0; i < m_length; i++)
		m_p[i] = arr.m_p[i];

	return *this;
}

const Matrix Matrix::operator+(const Matrix& m)const
{
	Matrix result = *this;

	for (int i = 0; i < m_length; i++)
	{
		result.m_p[i] = result.m_p[i] + m.getPolynom()[i];
		//std::cout << result.m_p[i] << "\t";
	}

	return result;
}

void Matrix::show()const
{
	std::cout << "Matrix: \n";
	for (int i = 0; i < m_length; i++)
		std::cout << m_p[i];
}
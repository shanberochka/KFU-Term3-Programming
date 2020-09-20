#include "Matrix.h"
//#include <iostream>
#include <iomanip>

void Matrix::initByZeros()
{
	m_matrix = new int* [m_rows];

	for (int i = 0; i < m_rows; i++)
	{
		m_matrix[i] = new int[m_cols];
		for (int j = 0; j < m_cols; j++)
			m_matrix[i][j] = 0;
	}
}
Matrix::Matrix()
{
	const int init = 3;
	m_cols = init;
	m_rows = init;

	Matrix::initByZeros();
}
Matrix::Matrix(int rows, int cols)
{
	m_rows = rows;
	m_cols = cols;

	Matrix::initByZeros();
}

Matrix::Matrix(const Matrix& M) : m_rows(M.m_rows), m_cols(M.m_cols)
{
	Matrix::initByZeros();
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			m_matrix[i][j] = M.m_matrix[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < m_rows; ++i)
		delete[] m_matrix[i];
	delete[] m_matrix;
}

int Matrix::getNumRows()
{
	return m_rows;
}

int Matrix::getNumCols()
{
	return m_cols;
}

int** Matrix::getMatrix()
{
	return m_matrix;
}

void Matrix::getFromConsole()
{
	std::cout << "Enter rows number: ";
	std::cin >> m_rows;
	std::cout << "Enter cols number: ";
	std::cin >> m_cols;
	Matrix::initByZeros();
	int elem;
	for (int i = 0; i < m_rows; ++i)
		for (int j = 0; j < m_cols; ++j)
		{
			std::cout << "a[" << i << "][" << j << "]=";
			std::cin >> elem;
			m_matrix[i][j] = elem;
		}
	std::cout << "\n";
}

void Matrix::printToConsole()
{
	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < m_cols; ++j)
		{
			std::cout << std::setw(5) << m_matrix[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void Matrix::getFromFile(std::ifstream& in)
{
	in >> m_rows >> m_cols;
	Matrix::initByZeros();
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			in >> m_matrix[i][j];
}

void Matrix::printToFile(std::ofstream& out)
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
			out << std::setw(5) << m_matrix[i][j];
		out << "\n";
	}
	out << "\n";
}

void Matrix::initRandom()
{
	srand(time(NULL));
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			m_matrix[i][j] = rand() % 100;
		}
	}
}

/*
Matrix Matrix::operator-(const Matrix& secondMatrix)const
{
	// проверка корректности
	Matrix result(*this);
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			result.m_matrix[i][j] -= secondMatrix.m_matrix[i][j];
		}
	}
	return result;
}
Matrix Matrix::operator+(const Matrix& secondMatrix)const
{
	// проверка корректности
	Matrix result(*this);
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			result.m_matrix[i][j] += secondMatrix.m_matrix[i][j];
		}
	}
	return result;
}

Matrix Matrix::operator*(const Matrix& secondMatrix)const
{
	Matrix result(m_rows, secondMatrix.m_cols);
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < secondMatrix.m_cols; j++)
			for (int k = 0; k < m_cols; k++)
				result.m_matrix[i][j] += m_matrix[i][k] * secondMatrix.m_matrix[j][k];
	return result;
}
*/
Matrix Matrix::add(const Matrix& secondMatrix)const
{
	Matrix result(*this);
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			result.m_matrix[i][j] += secondMatrix.m_matrix[i][j];
		}
	}
	return result;

}

Matrix Matrix::sub(const Matrix& secondMatrix)const
{
	Matrix result(*this);
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			result.m_matrix[i][j] -= secondMatrix.m_matrix[i][j];
		}
	}
	return result;
}

Matrix Matrix::mul(const Matrix& secondMatrix)const
{
	int rows{ (*this).m_rows };
	int cols{ secondMatrix.m_cols };
	int med{ (*this).m_cols };
	Matrix result(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			for (int k = 0; k < med; k++)
			result.m_matrix[i][j] += (*this).m_matrix[i][k] + secondMatrix.m_matrix[k][j];
		}
	}
	return result;
}

#pragma once
#include <iostream>
#include <fstream>
class Matrix
{
private:
	int** m_matrix;					// 
	int m_rows, m_cols;				// ���-�� ������ � ��������

public:
	Matrix();						// ����������� �� ���������
	Matrix(int, int);				// ����������� �� ����� �����, ��������
	Matrix(const Matrix&);			// ����������� �����������
	~Matrix();						// ����������

	int getNumRows();
	int getNumCols();

	int** getMatrix();

	void setNumRows();
	void setNumCols();

	void initRandom();

	void initByZeros();

	void T();

	Matrix add(const Matrix&)const;
	Matrix sub(const Matrix&)const;
	Matrix mul(const Matrix&)const;

	void getFromConsole();
	void printToConsole();

	void getFromFile(std::ifstream&);
	void printToFile(std::ofstream&);


	//Matrix operator+(const Matrix&)const;
	//Matrix operator-(const Matrix&)const;
	//Matrix operator*(const Matrix&)const;

	//friend std::istream& operator>>(std::istream&, Matrix&);
	//friend std::ostream& operator>>(std::ostream&, Matrix&);
};


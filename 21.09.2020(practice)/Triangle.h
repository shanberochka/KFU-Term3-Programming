#pragma once
class Triangle
{
private:
	int m_a, m_b, m_c;
	static bool checkCorrect(int, int, int);
public:
	Triangle();
	Triangle(int, int, int);
	~Triangle();

	int getA();
	int getB();
	int getC();


	void setA(int);
	void setB(int);
	void setC(int);

	void show();

	void changeA();
	void changeB();
	void changeC();

	int getPerimeter();
	double getSquare();

	double getInscibedCircleRadius()
	{
		return (2 * getSquare() / getPerimeter());
	}
	double getCircumCircleRadius()
	{
		return m_a * m_b * m_c / (4 * getSquare());
	}
};


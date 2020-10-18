#pragma once
#include<math.h>
#include<iostream>
using namespace std;
class Triangle
{
protected:
	double a, b, c;
	bool isCorrect(double x, double y, double z)
	{
		return ((x + y > z) && ((x + z) > y) && ((y + z) > x));
	}
	
public:
	Triangle();
	Triangle(double, double, double);
	Triangle(double, double);
	double get_a()
	{
		return a;
	};
	double get_b()
	{
		return b;
	};
	double get_c()
	{
		return c;
	}
	;
	void set_a(double x);
	void set_b(double y);
	void set_c(double z);
	void change_a(double x);
	void change_b(double y);
	void change_c(double z);

	double perimeter();
	double square();
	double radius();
	double Radius();
	void show();

	void isCorrect()
	{
		if ((a + b > c) && ((a + c) > b) && ((b + c) > a))
			 std::cout << "\Tringale is correct.\n";
		else 
			std::cout << "\Tringale is not correct.\n";
	}

};

#pragma once
#include "Triangle.h"
class RightAngle :public Triangle
{
public:
	RightAngle();
	RightAngle(double, double);

	double square();
	double radius();
	double Radius();
	void correct();

	void change_a(double x);
	void change_b(double y);
};
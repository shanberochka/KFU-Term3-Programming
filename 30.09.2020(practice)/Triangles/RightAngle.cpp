#include "RightAngle.h"
RightAngle::RightAngle() :Triangle()
{
	a = 3;
	b = 4;
	c = 5;
}
RightAngle::RightAngle(double x, double y) : Triangle(x, y)
{
	c = sqrt(a * a + b * b);
}
double RightAngle::square()
{
	return a * b / 2;
}
double RightAngle::radius()
{
	return 0.5 * perimeter() - c;
}
double RightAngle::Radius()
{
	return c / 2;
}
void RightAngle::correct()
{
	c = sqrt(a * a + b * b);
}
void RightAngle::change_a(double x)
{
	do
	{
		if (isCorrect(a + x, b, c))
		{
			a = a + x;
			correct();
		}
		else
		{
			std::cout << "Such a triangel can not exist.\n Try again\n";
			std::cout << "delta(a)=";
			std::cin >> x;
		}
	} while (!isCorrect(a + x, b, c));
}
void RightAngle::change_b(double y)
{
	do
	{
		if (isCorrect(a, b + y, c))
		{
			b = b + y;
			correct();
		}
		else
		{
			std::cout << "Such a triangel can not exist.\n Try again\n";
			std::cout << "delta(b)=";
			std::cin >> y;
		}
	} while (!isCorrect(a, b + y, c));
}

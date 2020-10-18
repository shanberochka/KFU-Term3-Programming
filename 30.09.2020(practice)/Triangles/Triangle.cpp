#include "Triangle.h"
Triangle::Triangle()
{
	a = 1;
	b = 1;
	c = 1;
};
Triangle::Triangle(double x, double y, double z)
{
	if (isCorrect(x, y, z))
	{
		a = x;
		b = y;
		c = z;
	}
	else
	{
		std::cout << "Such a triangel can not exist.\nDefault initialisation.\n";
		a = 1;
		b = 1;
		c = 1;
	}
}
Triangle::Triangle(double x, double y)
{
	if (isCorrect(x, y, y))
	{
		a = x;
		b = y;
		c = y;
	}
	else
	{
		std::cout << "Such a triangel can not exist.\nDefault initialisation.\n";
		a = 1;
		b = 1;
		c = 1;
	}
}

void Triangle::set_a(double x)
{
	do
	{
		if (isCorrect(x, b, c))
		{
			a = x;
		}
		else
		{
			std::cout << "Such a triangel can not exist.\n Try again\n";
			std::cout << "a=";
			std::cin >> x;
		}
	} while (!isCorrect(x, b, c));
};
void Triangle::set_b(double y)
{
	do
	{
		if (isCorrect(a, y, c))
		{
			b = y;
		}
		else
		{
			std::cout << "Such a triangel can not exist.\n Try again\n";
			std::cout << "b=";
			std::cin >> y;
		}
	} while (!isCorrect(a, y, c));
};
void Triangle::set_c(double z)
{
	do
	{
		if (isCorrect(a, b, z))
		{
			c = z;
		}
		else
		{
			std::cout << "Such a triangel can not exist.\n Try again\n";
			std::cout << "c=";
			std::cin >> z;
		}
	} while (!isCorrect(a, b, z));
};
void Triangle::change_a(double x)
{
	do
	{
		if (isCorrect(a + x, b, c))
		{
			a = a + x;
		}
		else
		{
			std::cout << "Such a triangel can not exist.\n Try again\n";
			std::cout << "delta(a)=";
			std::cin >> x;
		}
	} while (!isCorrect(a + x, b, c));
};
void Triangle::change_b(double y)
{
	do
	{
		if (isCorrect(a, b + y, c))
		{
			b = b + y;
		}
		else
		{
			std::cout << "Such a triangel can not exist.\n Try again\n";
			std::cout << "delta(b)=";
			std::cin >> y;
		}
	} while (!isCorrect(a, b + y, c));
};
void Triangle::change_c(double z)
{
	do
	{
		if (isCorrect(a, b, c + z))
		{
			c = c + z;
		}
		else
		{
			std::cout << "Such a triangel can not exist.\n Try again\n";
			std::cout << "delta(c)=";
			std::cin >> z;
		}
	} while (!isCorrect(a, b, c + z));
};
double Triangle::perimeter()
{
	return a + b + c;
};
double Triangle::square()
{
	double p;
	p = perimeter() * 0.5;
	return sqrt(p * (p - a) * (p - b) * (p - c));
};
double Triangle::radius()
{
	return 2 * square() / perimeter();
};
double Triangle::Radius()
{
	return a * b * c / (4 * square());
};
void Triangle::show()
{
	cout << "AB= " << a << endl;
	cout << "AC= " << b << endl;
	cout << "BC= " << c << endl;
};



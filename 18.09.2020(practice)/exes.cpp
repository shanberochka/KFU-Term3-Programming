#include "DinamicArray.h"
#include "Polynomial.h"
#include "FixRowArray.h"
#include <iostream>

void ex6()
{
	DinamicArray arr(5);
	arr.initRandom();
	arr.print();
	arr.shuffle();
	arr.print();
	std::cout << arr.getDiffCount();
}

void ex8()
{
	Polynomial p1(2);
	p1.init();
	std::cout << "p1: " << p1;

	Polynomial p2(3);
	p2.init();
	std::cout << "p2: " << p2;

	std::cout << p1.getResult(1);

	std::cout << "p1+p2: " << p1 + p2;
	std::cout << "p1-p2: " << p1 - p2;
	std::cout << "p1*p2: " << p1 * p2;
}

void ex7()
{
	FixRowArray text(3, 4);
	text.init();
	text.print();
	//text.printLine(2);

	text.merge(1, 3);
	text.print();

	//text.excludeMerge(2, 3);
	//text.print();
}
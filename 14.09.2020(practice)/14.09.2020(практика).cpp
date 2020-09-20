#include <iostream>
#include "Matrix.h"
#include <fstream>

int main()
{
	Matrix A;
	std::ifstream in("matrix1.txt");
	A.getFromFile(in);
	in.close();

	Matrix B;
	in.open("matrix2.txt");
	B.getFromFile(in);
	in.close();

	std::ofstream out("out.txt");

	//A.add(B).printToFile(out);
	//B.sub(A).printToFile(out);
	//A.mul(B).printToFile(out);
	out.close();

	//B.sub(A).printToConsole();

	Matrix C;
	C.printToConsole();
	C.initRandom();
	C.printToConsole();
	C.getFromConsole();
	C.printToConsole();
}

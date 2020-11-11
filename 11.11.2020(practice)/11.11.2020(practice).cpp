#include <iostream>
#include <fstream>
#include "Set.h"

int main()
{
	Set mySet;
	mySet.Add(7);
	mySet.Add(7);
	mySet.Add(1);
	std::cout << "Size is:" << mySet.GetSize() << std::endl;
	mySet.Del(8);
	mySet.Add(12);
	mySet.Add(1);
	mySet.Add(10);
	mySet.Add(11);
	mySet.Add(19);
	mySet.Add(16);
	mySet.Add(17);

	std::ofstream out("primes_from_set.txt");
	mySet.PrintToFilePrimes(out);

	out.close();
}


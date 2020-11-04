#include "Set.h"
#include <iostream>
using namespace std;

void ex()
{
	setlocale(LC_ALL, "Russian");
	Set s1;
	Set s2;
	Set s3;

	s1 = s1 + 'A';
	s1 = s1 + 'B';
	s1 = s1 + 'C';

	cout << " множество s1 после добавления символов  A B C : " << endl;
	s1.showset();

	cout << endl;

	cout << " тестирование членства с помощью функции isMember()." << endl;

	if (s1.isMember('B'))
		cout << " B - член множества s1. " << endl;
	else
		cout << " B -  не член множества s1." << endl;


	if (s1.isMember('T'))
		cout << " T - член множества s1." << endl;
	else
		cout << " T - не член множества s1. " << endl;

	cout << endl;

	s1 = s1 - 'B';

	cout << " множество s1 после s1=s1-'B':  " << endl;
	s1.showset();
	s1 = s1 - 'C';

	cout << " множество s1 после s1=s1-'C':  " << endl;
	s1.showset();

	cout << endl;

	s1 = s1 + 'A';
	s1 = s1 + 'B';
	s1 = s1 + 'C';

	cout << " множество s1 после добавления символов A B C : " << endl;
	s1.showset();

	cout << endl;

	s2 = s2 + 'A';
	s2 = s2 + 'X';
	s2 = s2 + 'W';

	cout << " множество s2 после добавления символов A X W : " << endl;
	s2.showset();

	cout << endl;


	s3 = s1 + s2;

	cout << " множество s3 после s3=s1+s2 : " << endl;
	s3.showset();

	s3 = s3 - s1;

	cout << " множество s3 после s3=s3-s1 : " << endl;
	s3.showset();
	cout << endl;
	s2 = s2 - s2;// очищаем  s2
	cout << " множество s2 после s2=s2-s2 : " << endl;
	s2.showset();


	cout << endl;

	s2 = s2 + 'C';
	// помещаем символы ABC в обратном порядке 
	s2 = s2 + 'B';
	s2 = s2 + 'A';

	cout << " множество s2 после добавления C B A: " << endl;
	s2.showset();
	cout << endl;

	Set s4;// пустое множество 
	cout << "   s4-пустое множество  :" << endl;
	s4.showset();

	for (char ch = 'A'; ch <= 'Z'; ch++)
		s4 = s4 + ch;
	cout << " множество s4 после добавления всего латинского алфавита : " << endl;
	s4.showset();
	cout << endl;

}
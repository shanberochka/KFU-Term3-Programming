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

	cout << " ��������� s1 ����� ���������� ��������  A B C : " << endl;
	s1.showset();

	cout << endl;

	cout << " ������������ �������� � ������� ������� isMember()." << endl;

	if (s1.isMember('B'))
		cout << " B - ���� ��������� s1. " << endl;
	else
		cout << " B -  �� ���� ��������� s1." << endl;


	if (s1.isMember('T'))
		cout << " T - ���� ��������� s1." << endl;
	else
		cout << " T - �� ���� ��������� s1. " << endl;

	cout << endl;

	s1 = s1 - 'B';

	cout << " ��������� s1 ����� s1=s1-'B':  " << endl;
	s1.showset();
	s1 = s1 - 'C';

	cout << " ��������� s1 ����� s1=s1-'C':  " << endl;
	s1.showset();

	cout << endl;

	s1 = s1 + 'A';
	s1 = s1 + 'B';
	s1 = s1 + 'C';

	cout << " ��������� s1 ����� ���������� �������� A B C : " << endl;
	s1.showset();

	cout << endl;

	s2 = s2 + 'A';
	s2 = s2 + 'X';
	s2 = s2 + 'W';

	cout << " ��������� s2 ����� ���������� �������� A X W : " << endl;
	s2.showset();

	cout << endl;


	s3 = s1 + s2;

	cout << " ��������� s3 ����� s3=s1+s2 : " << endl;
	s3.showset();

	s3 = s3 - s1;

	cout << " ��������� s3 ����� s3=s3-s1 : " << endl;
	s3.showset();
	cout << endl;
	s2 = s2 - s2;// �������  s2
	cout << " ��������� s2 ����� s2=s2-s2 : " << endl;
	s2.showset();


	cout << endl;

	s2 = s2 + 'C';
	// �������� ������� ABC � �������� ������� 
	s2 = s2 + 'B';
	s2 = s2 + 'A';

	cout << " ��������� s2 ����� ���������� C B A: " << endl;
	s2.showset();
	cout << endl;

	Set s4;// ������ ��������� 
	cout << "   s4-������ ���������  :" << endl;
	s4.showset();

	for (char ch = 'A'; ch <= 'Z'; ch++)
		s4 = s4 + ch;
	cout << " ��������� s4 ����� ���������� ����� ���������� �������� : " << endl;
	s4.showset();
	cout << endl;

}
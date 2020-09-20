#include "Student.h"
#include<iostream>
#include <string>
using namespace std;

Student::Student(void)
{

}
Student::~Student(void)
{
	//delete[] Marks;
}

void Student::setFullName(string fullname)
{
	FullName = fullname;
}
string Student::getFullName()const
{
	return FullName;
}
void Student::setGroup(int group)
{
	Group = group;
}

int Student::getGroup()const
{
	return Group;
}
void Student::setMarks(int marks[5])
{
	int sum{};
	for (int i = 0; i < 5; ++i)
	{
		sum += marks[i];
		Marks[i] = marks[i];
	}
	AvMark = static_cast<double>(sum) / 5;
}

int* Student::getMarks()
{
	return Marks;
}

double Student::getAverageMark()const
{
	return AvMark;
}

bool Student::isOk()
{
	bool ok = true;
	for (int i = 0; i < 5; ++i)
	{
		ok &= (Marks[i] == 5 || Marks[i] == 4);
	}
	return ok;
}
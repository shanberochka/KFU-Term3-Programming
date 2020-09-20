#pragma once
#include <string>
class Student
{
private:
	std::string FullName;
	int Group;
	int Marks[5];
	double AvMark;

public:
	void setFullName(std::string);
	std::string getFullName() const;
	void setGroup(int);
	int getGroup() const;
	void setMarks(int[]);
	int* getMarks();
	double getAverageMark() const;

	bool isOk();

	Student(void);
	~Student();
};


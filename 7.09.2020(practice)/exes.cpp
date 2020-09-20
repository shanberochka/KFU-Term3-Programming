#include "Student.h"
#include "Train.h"
#include <iostream>
#include <string>
#include <algorithm>

void getGroup(Student* group, int num)
{
	std::string name;
	int groupNum;
	int marks[5];

	for (int i = 0; i < num; ++i)
	{
		std::cout << '\n';
		std::cout << "Enter the name: ";
		std::cin >> name;
		group[i].setFullName(name);

		std::cout << "Enter the group: ";
		std::cin >> groupNum;
		group[i].setGroup(groupNum);

		std::cout << "Enter marks: ";
		for (int j = 0; j < 5; ++j)
		{
			std::cin >> marks[j];
		}
		group[i].setMarks(marks);
	}
	//std::cout << std::string(10, '-');
}
void sort(Student* group, int num)
{
	std::cout << "\n\tSorted list of students:\n";
	int i, j;
	Student s;
	for (i = 0; i < num - 1; ++i)
		for (j = i+1; j < num; ++j)
			if (group[i].getAverageMark() > group[j].getAverageMark())
			{

				//std::cout << "Compairing: " << group[i].getAverageMark() << " : " << group[j].getAverageMark() << '\n';
				s = group[i];
				group[i] = group[j];
				group[j] = s;
			}
}
void show(Student* group, int num)
{
	std::cout << "\nThe group:\n";
	for (int i = 0; i < num; ++i)
	{
		std::cout << "FullName: " << group[i].getFullName() << "\n" << "Group: " << group[i].getGroup() << "\n" << "Marks: ";
		for (int j = 0; j < 5; ++j)
		{
			std::cout << group[i].getMarks()[j] << " ";
		}
		std::cout << "\n====================\n";
	}
}
void showOk(Student* group, int num)
{
	std::cout << "\nThe list of ok students:\n";
	for (int i = 0; i < num; ++i)
	{
		if (group[i].isOk())
			std::cout << group[i].getFullName() << " from group " << group[i].getGroup() << "\n";
	}
}

void ex1()
{
	const int numStud = 2;
	Student pmi[numStud]{};

	std::cout << "\t\tList of students: \n" << std::string(50, '-') << '\n';
	getGroup(pmi, numStud);

	show(pmi, numStud);
	
	sort(pmi, numStud);

	show(pmi, numStud);

	showOk(pmi, numStud);
	//delete pmi;
}

void getTrains(Train* trains, int num)
{
	std::string destination;
	int trainNum;
	std::string timeDeparture;
	std::cout << "Enter trains: \n" << std::endl;

	for (int i = 0; i < num; ++i)
	{
		std::cout << "#" << i + 1 << "\n";
		std::cout << "Destination: ";
		std::cin >> destination;
		trains[i].setDestination(destination);

		std::cout << "Train number: ";
		std::cin >> trainNum;
		trains[i].setTrainNum(trainNum);

		std::cout << "Time of the departure: ";
		std::cin >> timeDeparture;
		trains[i].setTimeDeparture(timeDeparture);

		std::cout << "\n";

	}
}

void show(Train* trains, int num)
{
	std::cout << "\nList of trains\n";
	std::cout << "Number\tDestination\tTime\n";
	for (int i = 0; i < num; ++i)
		std::cout << trains[i].getTrainNum() << "\t" << trains[i].getDestination() << "\t" << trains[i].getTimeDeparture() << "\n";
}

void sortByTrainNum(Train* trains, int num)
{
	std::cout << "\nSort by train number\n";
	int i, j;
	Train t;
	for (i = 0; i < num - 1; ++i)
		for (j = i + 1; j < num; ++j)
			if (trains[i].getTrainNum() > trains[j].getTrainNum())
			{
				t = trains[i];
				trains[i] = trains[j];
				trains[j] = t;
			}
}

void printTrainInfo(Train train)
{
	std::cout << "\tDestination:" << train.getDestination() << "\n\tTime: " << train.getTimeDeparture() << "\n";
}

void findTrain(Train* trains, int num, int userNum)
{
	int i;
	bool find = false;
	for (i = 0; i < num && !find; i++)
	{
		if (trains[i].getTrainNum() == userNum)
			find = true;
	}
	if (find)
		printTrainInfo(trains[i-1]);
	else
		std::cout << "Not found.\n";
}

void sortByDestinationAndTime(Train* trains, int num)
{
	std::cout << "\nSort by destination and time\n";
	int i, j;
	Train t;
	for (i = 0; i < num - 1; ++i)
		for (j = i + 1; j < num; ++j)
		{
			if (trains[i].getDestination() > trains[j].getDestination())
			{
				std::swap(trains[i], trains[j]);
			}
			if ((trains[i].getDestination() == trains[j].getDestination()) && (trains[i].getTimeDeparture() > trains[j].getTimeDeparture()))
			{
				std::swap(trains[i], trains[j]);
			}
		}
			
}

void ex2()
{
	const int num = 5;
	Train trains[num]{};
	getTrains(trains, num);

	show(trains, num);
	sortByTrainNum(trains, num);
	show(trains, num);

	int userNum;
	
	sortByDestinationAndTime(trains, num);

	show(trains, num);

	std::cout << "Do you want to find train?(1-yes, 0-no): ";
	std::cin >> userNum;
	if (userNum == 1)
	{
		std::cout << "Number of train: ";
		std::cin >> userNum;
		findTrain(trains, num, userNum);
	}
	//delete trains;
}
#pragma once
#include <string>

class Train
{
private:
	std::string m_destination;
	int m_trainNum;
	std::string m_timeDeparture;

public:
	void setDestination(std::string);
	std::string getDestination();

	void setTrainNum(int);
	int getTrainNum();

	void setTimeDeparture(std::string);
	std::string getTimeDeparture();

	Train(void);
	//Train(std::string&, int, std::string&);
	~Train();
};


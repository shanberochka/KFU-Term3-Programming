#include "Train.h"
#include <string>

Train::Train(void)
{

}
/*Train::Train(std::string &destination, int trainNum, std::string &timeDeparture)
	:m_destination(destination), m_trainNum(trainNum), m_timeDeparture(timeDeparture)
{

}
*/
Train::~Train(void)
{

}


void Train::setDestination(std::string destination)
{
	m_destination = destination;
}
std::string Train::getDestination()
{
	return m_destination;
}

void Train::setTrainNum(int trainNum)
{
	m_trainNum = trainNum;
}

int Train::getTrainNum()
{
	return m_trainNum;
}

void Train::setTimeDeparture(std::string timeDeparture)
{
	m_timeDeparture = timeDeparture;
}
std::string Train::getTimeDeparture()
{
	return m_timeDeparture;
}
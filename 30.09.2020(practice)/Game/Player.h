#pragma once
#include "Creature.h"
#include <iostream>
#include <cstring>
class Player :
	public Creature
{
	int m_level = 1;
public:
	Player(std::string);
	
	int getLevel();

	bool hasWon();

	void levelUp();
};


#pragma once
#include <iostream>
#include <cstring>
class Creature
{
protected:
	std::string m_name;
	char m_symbol;
	int m_health;
	int m_damage;
	int m_gold;

public:
	Creature();
	Creature(std::string, char, int, int, int);
	
	const std::string& getName();
	char getSymbol();
	int getHealth();
	int getDamage();
	int getGold();

	void reduceHealth(int);
	bool isDead();
	void addGold(int);
};


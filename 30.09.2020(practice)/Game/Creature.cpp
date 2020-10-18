#include "Creature.h"
Creature::Creature()
{
}
Creature::Creature(std::string name, char symbol, int health, int damage, int gold):
	m_name(name), m_symbol(symbol), m_health(health), m_damage(damage), m_gold(gold)
{

}
const std::string& Creature::getName()
{
	return m_name;
}
char Creature::getSymbol()
{
	return m_symbol;
}
int Creature::getHealth()
{
	return m_health;
}
int Creature::getDamage()
{
	return m_damage;
}
int Creature::getGold()
{
	return m_gold;
}

void Creature::reduceHealth(int health)
{
	m_health -= health;
}
bool Creature::isDead()
{
	return (m_health <= 0);
}
void Creature::addGold(int gold)
{
	m_gold += gold;
}
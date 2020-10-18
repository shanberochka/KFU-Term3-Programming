#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>
#include <cstdlib> // ��� rand() � srand()
#include <ctime> // ��� time()

// ���������� ��������� ����� ����� min � max
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// ���������� ������������ ��������� �������� �� ���������
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}


// ���� ����� ������������ ����� ������� �������
void attackMonster(Player& p, Monster& m)
{
	// ���� ����� �����, �� �� �� ����� ��������� �������
	if (p.isDead())
		return;

	std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";

	// �������� ������� ����������� �� ����� ������
	m.reduceHealth(p.getDamage());

	// ���� ������ �����, �� ����������� level ������
	if (m.isDead())
	{
		std::cout << "You killed the " << m.getName() << ".\n";
		p.levelUp();
		std::cout << "You are now level " << p.getLevel() << ".\n";
		std::cout << "You found " << m.getGold() << " gold.\n";
		p.addGold(m.getGold());
	}
}

// ���� ����� ������������ ����� ������ ��������
void attackPlayer(Monster& m, Player& p)
{
	// ���� ������ �����, �� �� �� ����� ��������� ������
	if (m.isDead())
		return;

	// �������� ������ ����������� �� ����� �������
	p.reduceHealth(m.getDamage());
	std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
}

void fightMonster(Player &p)
{
	// ������� ���������� ���������� �������
	Monster m = Monster::getRandomMonster();
	std::cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ").\n";

	// ���� ������ ��� ����� �� �����, �� ��� ������������
	while (!m.isDead() && !p.isDead())
	{
		std::cout << "(R)un or (F)ight: ";
		char input;
		std::cin >> input;
		if (input == 'R' || input == 'r')
		{
			// 50/50 ���� �������� ������
			if (getRandomNumber(1, 2) == 1)
			{
				std::cout << "You successfully fled.\n";
				return; // ������� � �������� ������� ��������
			}
			else
			{
				std::cout << "You failed to flee.\n";
				attackPlayer(m, p);
				continue;
			}
		}

		if (input == 'F' || input == 'f')
		{
			attackMonster(p, m);
			attackPlayer(m, p);
		}
	}
}

void exGame()
{
	srand(static_cast<unsigned int>(time(0))); // ������������� �������� ��������� ����� � �������� ���������� �����
	rand(); // ���������� ������ ���������

	std::cout << "Enter your name: ";
	std::string playerName;
	std::cin >> playerName;

	Player player(playerName);
	std::cout << "Welcome, " << player.getName() << "\n";

	while (!player.hasWon() && !player.isDead())
		fightMonster(player);

	if (player.isDead())
	{
		std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
		std::cout << "Too bad you can't take it with you!\n";
	}
	else
	{
		std::cout << "You won the game with " << player .getGold() << " gold!\n";
	}
}

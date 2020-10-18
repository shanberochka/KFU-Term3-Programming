#include "Monster.h"

#include <cstdlib> // для rand() и srand()
#include <ctime> // для time()

// Генерируем рандомное число между min и max
int getRandomNumber4(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем генерацию значения из диапазона
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};

Monster::Monster(Monster::Type type): Creature(Monster::monsterData[type].name, Monster::monsterData[type].symbol, monsterData[type].health, Monster::monsterData[type].damage, Monster::monsterData[type].gold)
{
	// таблица поиска - массив, который сожержит все предопределенные атрибуты(свойства) чего-либо

}

Monster Monster::getRandomMonster()
{
	Type type = static_cast<Type>(getRandomNumber4(0, MAX_TYPES - 1));
	return Monster(type);
}

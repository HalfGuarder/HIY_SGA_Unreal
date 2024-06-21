#include "pch.h"
#include "HobGoblin.h"

HobGoblin::HobGoblin(string name, int hp, int mp, int atk, int exp)
	:Monster(name, hp, mp, atk, exp)
{
}

HobGoblin::~HobGoblin()
{
}

void HobGoblin::Attack(Creature* other)
{
}

int HobGoblin::GiveExp()
{
	return 0;
}

void HobGoblin::Recovery()
{
}

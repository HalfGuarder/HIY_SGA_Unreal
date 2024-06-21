#include "pch.h"
#include "Goblin.h"

Goblin::Goblin(string name, int hp, int mp, int atk, int exp)
	:Monster(name, hp, mp, atk, exp)
{
}

Goblin::~Goblin()
{
}

void Goblin::Attack(Creature* other)
{
	if (IsDead() || other->IsDead())
	{
		return;
	}

	this->Creature::PreAttack(other);

	other->TakeDamage(_atk);
}


int Goblin::GiveExp()
{
	if (!IsDead())
	{
		return 0;
	}

	int exp = _exp;
	_exp = 0;

	return exp;
}

void Goblin::Recovery()
{
	_curHp = _maxHp;
	_curMp = _maxMp;

	return;
}
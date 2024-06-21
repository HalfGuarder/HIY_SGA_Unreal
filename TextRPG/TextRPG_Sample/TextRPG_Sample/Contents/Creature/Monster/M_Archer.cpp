#include "pch.h"
#include "M_Archer.h"

M_Archer::M_Archer(string name, int hp, int mp, int atk, int exp)
	:Monster(name, hp, mp, atk, exp)
{
}

M_Archer::~M_Archer()
{
}

void M_Archer::Attack(Creature* other)
{
	if (IsDead() || other->IsDead())
	{
		return;
	}

	this->Creature::PreAttack(other);

	int num = rand() % 100;
	float ratio = num / (float)99;

	if (ratio < 0.3f)
	{
		cout << "크리티컬 공격! 데미지 3배!" << endl;
		other->TakeDamage(_atk * 3.0f);
	}
	else
	{
		other->TakeDamage(_atk);
	}
}

int M_Archer::GiveExp()
{
	if (!IsDead())
	{
		return 0;
	}

	int exp = _exp;
	_exp = 0;

	return exp;
}

void M_Archer::Recovery()
{
	_curHp = _maxHp;
	_curMp = _maxMp;
	_exp = 100;

	return;
}
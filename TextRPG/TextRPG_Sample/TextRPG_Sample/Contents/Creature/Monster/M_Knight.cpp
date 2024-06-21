#include "pch.h"
#include "M_Knight.h"

M_Knight::M_Knight(string name, int hp, int mp, int atk, int exp)
	:Monster(name, hp, mp, atk, exp)
{
}

M_Knight::~M_Knight()
{
}

void M_Knight::Attack(Creature* other)
{
	if (IsDead() || other->IsDead())
	{
		return;
	}

	this->Creature::PreAttack(other);
	float ratio = (float)_curHp / (float)_maxHp;

	if (ratio < 0.5f)
	{
		cout << "기사회생! 데미지 2배!" << endl;
		other->TakeDamage(_atk * 2);
	}
	else
	{
		other->TakeDamage(_atk);
	}
}

int M_Knight::GiveExp()
{
	if (!IsDead())
	{
		return 0;
	}

	int exp = _exp;
	_exp = 0;

	return exp;
}

void M_Knight::Recovery()
{
	_curHp = _maxHp;
	_curMp = _maxMp;

	return;
}
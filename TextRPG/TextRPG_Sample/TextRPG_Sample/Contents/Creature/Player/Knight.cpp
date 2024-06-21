#include "pch.h"
#include "Knight.h"

Knight::Knight(string name, int hp, int mp, int atk, int exp)
	:Player(name, hp, mp, atk, exp)
{
}

Knight::~Knight()
{

}

void Knight::Attack(Creature* other)
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

	if (other->IsDead())
	{
		Monster* checkIsDead = dynamic_cast<Monster*>(other);

		if (checkIsDead != nullptr)
		{
			TakeExp(checkIsDead);
		}
	}
}

void Knight::TakeExp(Monster* monster)
{
	int exp = monster->GiveExp();

	_exp += exp;
	_maxHp += exp / 10;
	_maxMp += exp / 10;
	_atk += exp / 10;

	return;
}

void Knight::Recovery()
{
	_curHp = _maxHp;
	_curMp = _maxMp;

	return;
}

int Knight::ReturnHpStat()
{
	return _maxHp;
}

int Knight::ReturnMpStat()
{
	return _maxMp;
}

int Knight::ReturnAtkStat()
{
	return _atk;
}
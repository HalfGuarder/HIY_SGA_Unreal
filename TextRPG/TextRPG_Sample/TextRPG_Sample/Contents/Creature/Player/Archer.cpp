#include "pch.h"
#include "Archer.h"

Archer::Archer(string name, int hp, int mp, int atk, int exp)
:Player(name, hp, mp, atk, exp)
{
}

Archer::~Archer()
{
}

void Archer::Attack(Creature* other)
{
	if (IsDead() || other->IsDead())
	{
		return;
	}

	// 30프로 확률
	// 0 ~ 99까지의 난수를 뽑고
	// 100으로 나눔
	this->Creature::PreAttack(other); // 멤버 함수를 호출하기 위한 조건 ... 객체가 항상 있어야 한다.
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

	if (other->IsDead())
	{
		Monster* checkIsDead = dynamic_cast<Monster*>(other);

		if (checkIsDead != nullptr)
		{
			TakeExp(checkIsDead);
		}
	}
}

void Archer::TakeExp(Monster* monster)
{
	int exp = monster->GiveExp();

	_exp += exp;
	_maxHp += exp / 10;
	_maxMp += exp / 10;
	_atk += exp / 10;

	return;
}

void Archer::Recovery()
{
	_curHp = _maxHp;
	_curMp = _maxMp;

	return;
}

int Archer::ReturnHpStat()
{
	return _maxHp;
}

int Archer::ReturnMpStat()
{
	return _maxMp;
}

int Archer::ReturnAtkStat()
{
	return _atk;
}
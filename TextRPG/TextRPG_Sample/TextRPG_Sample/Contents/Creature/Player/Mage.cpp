#include "pch.h"
#include "Mage.h"

Mage::Mage(string name, int hp, int mp, int atk, int exp)
	:Player(name, hp, mp, atk, exp)
{
}

Mage::~Mage()
{

}

void Mage::Attack(Creature* other)
{
	if (IsDead() || other->IsDead())
	{
		return;
	}

	this->Creature::PreAttack(other);
	
	if (_curMp <= 0)
	{
		cout << "마나 부족 - 공격을 쉬고 마나를 회복합니다." << endl;
		_curMp = _maxMp;
	}
	else
	{
		_curMp -= 5;
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

void Mage::TakeExp(Monster* monster)
{
	int exp = monster->GiveExp();

	_exp += exp;
	_maxHp += exp / 10;
	_maxMp += exp / 10;
	_atk += exp / 10;

	return;
}

void Mage::Recovery()
{
	_curHp = _maxHp;
	_curMp = _maxMp;

	return;
}

int Mage::ReturnHpStat()
{
	return _maxHp;
}

int Mage::ReturnMpStat()
{
	return _maxMp;
}

int Mage::ReturnAtkStat()
{
	return _atk;
}

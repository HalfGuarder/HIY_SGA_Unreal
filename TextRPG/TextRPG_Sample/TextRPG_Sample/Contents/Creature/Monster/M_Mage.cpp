#include "pch.h"
#include "M_Mage.h"

M_Mage::M_Mage(string name, int hp, int mp, int atk, int exp)
	:Monster(name, hp, mp, atk, exp)
{
}

M_Mage::~M_Mage()
{
}

void M_Mage::Attack(Creature* other)
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
}

int M_Mage::GiveExp()
{
	if (!IsDead())
	{
		return 0;
	}

	int exp = _exp;
	_exp = 0;

	return exp;
}

void M_Mage::Recovery()
{
	_curHp = _maxHp;
	_curMp = _maxMp;

	return;
}
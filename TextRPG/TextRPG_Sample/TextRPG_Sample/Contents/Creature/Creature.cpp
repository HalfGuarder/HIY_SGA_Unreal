#include "pch.h"
#include "Creature.h"

Creature::Creature(string name, int hp, int mp, int atk, int exp)
	: _name(name), _curHp(hp), _curMp(mp), _atk(atk),
	_maxHp(hp), _maxMp(mp), _exp(exp)
{
}

Creature::~Creature()
{
}

void Creature::PrintInfo()
{
	Player* playerCheck = dynamic_cast<Player*>(this);

	cout << "~~~~~ 정보 ~~~~~" << endl;
	cout << "이름 : " << _name << endl;
	cout << "HP : " << _curHp << endl;
	cout << "Mp : " << _curMp << endl;
	cout << "ATK : " << _atk << endl;
	if (playerCheck != nullptr)
		cout << "EXP : " << _exp << endl;
	cout << "~~~~~~~~~~~~~~~~" << endl;
}

void Creature::PreAttack(Creature* other)
{
	cout << _name << "의 " << other->_name << "공격!" << endl;
}

void Creature::TakeDamage(int amount)
{
	_curHp -= amount;

	if (_curHp < 0)
	{
		_curHp = 0;
	}

	PrintInfo();
}


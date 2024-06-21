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

	cout << "~~~~~ ���� ~~~~~" << endl;
	cout << "�̸� : " << _name << endl;
	cout << "HP : " << _curHp << endl;
	cout << "Mp : " << _curMp << endl;
	cout << "ATK : " << _atk << endl;
	if (playerCheck != nullptr)
		cout << "EXP : " << _exp << endl;
	cout << "~~~~~~~~~~~~~~~~" << endl;
}

void Creature::PreAttack(Creature* other)
{
	cout << _name << "�� " << other->_name << "����!" << endl;
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


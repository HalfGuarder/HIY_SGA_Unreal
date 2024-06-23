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

void HobGoblin::TakeDamage(Creature* other, int amount)
{
	vector<Creature*>::iterator iter = 

	for()

	_curHp -= amount;

	if (_curHp < 0)
	{
		_curHp = 0;
	}

	PrintInfo();
}

int HobGoblin::GiveExp()
{
	return 0;
}

void HobGoblin::Recovery()
{
}

void HobGoblin::Set_PList(Creature* player)
{
	_pList.push_back(player);
}


void HobGoblin::Set_AggroList(vector<Creature*> player)
{

}

void HobGoblin::Modify_AggroList(vector<Creature*> player, int amount)
{

}

void HobGoblin::Sort_AggroList()
{

}

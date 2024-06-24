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
	if (IsDead())
	{
		return;
	}

	Sort_AggroTable();

	int atkCount= 0;

	vector<AggroInfo>::iterator iter = _aggroTable.begin();

	for (iter = _aggroTable.begin(); iter != _aggroTable.end(); iter++)
	{
		if (iter->_player->IsDead())
		{
			continue;
		}

		this->Creature::PreAttack(iter->_player);
		iter->_player->TakeDamage(_atk);
		atkCount++;

		if (atkCount == 4)
		{
			return;
		}
	}
}

void HobGoblin::TakeDamage(int amount, Creature* attacker)
{
	vector<AggroInfo>::iterator iter = _aggroTable.begin();

	iter = std::find_if(_aggroTable.begin(), _aggroTable.end(), [attacker](const AggroInfo info) -> bool
		{
			if (info._player == attacker)
			{
				return true;
			}
			return false;
		});

	if (iter != _aggroTable.end())
	{
		iter->_dmgAmount += amount;
	}
	else
	{
		AggroInfo add = AggroInfo(attacker, amount);

		_aggroTable.push_back(add);
	}

	_curHp -= amount;

	if (_curHp < 0)
	{
		_curHp = 0;
	}

	PrintInfo();
}

int HobGoblin::GiveExp()
{
	if (!IsDead())
	{
		return 0;
	}

	int exp = _exp;
	_exp = 0;

	return exp;
}

void HobGoblin::Recovery()
{
	_curHp = _maxHp;
	_curMp = _maxMp;

	return;
}

void HobGoblin::Sort_AggroTable()
{
	std::sort(_aggroTable.begin(), _aggroTable.end(), [](const AggroInfo a, const AggroInfo b) -> bool
		{
			if (a._dmgAmount > b._dmgAmount)
			{
				return true;
			}
			return false;
		});
}

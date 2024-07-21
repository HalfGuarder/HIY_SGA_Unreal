#pragma once

#include "pch.h"

struct AggroInfo
{
	AggroInfo(Creature* player, int dmg) : _player(player), _dmgAmount(dmg) {}

	Creature* _player;
	int _dmgAmount;
};

class AggroManage
{
public:


private:
	vector<AggroInfo> _aggroTable;
};


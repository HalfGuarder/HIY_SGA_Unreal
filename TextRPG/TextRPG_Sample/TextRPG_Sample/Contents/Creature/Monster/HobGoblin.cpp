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

int HobGoblin::GiveExp()
{
	return 0;
}

void HobGoblin::Recovery()
{
}

void HobGoblin::Set_AggroList(vector<Creature*> player)
{
	//for (int i = 0; i < 10; i++)
	//{
		_aggroList[player] = DamageInfo(0);
		_aggroList.insert(make_pair<P_Key, DamageInfo>(P_Key(player), DamageInfo(0)));
	//}
}

void HobGoblin::Modify_AggroList(vector<Creature*> player, int amount)
{

	std::map<P_Key, DamageInfo>::iterator it = _aggroList.begin();
	_aggroList.insert(std::pair<P_Key, DamageInfo>(player, amount)); // 기존에 쌓인 데미지에 추가하기
}

void HobGoblin::Sort_AggroList()
{

}

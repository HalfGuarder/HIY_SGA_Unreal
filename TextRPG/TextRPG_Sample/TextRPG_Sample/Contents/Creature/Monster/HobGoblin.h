#pragma once

struct AggroInfo
{
	AggroInfo(Creature* player, int dmg) : _player(player), _dmgAmount(dmg) {}

	Creature* _player;
	int _dmgAmount;
};

class HobGoblin : public Monster
{
public:
	HobGoblin(string name, int hp, int mp, int atk, int exp);
	virtual ~HobGoblin();

	virtual void Attack(Creature* other) override;
	virtual void TakeDamage(int amount, Creature* attacker) override;

	virtual int GiveExp() override;

	virtual void Recovery() override;

	void Sort_AggroTable();


private:
	vector<AggroInfo> _aggroTable;
};


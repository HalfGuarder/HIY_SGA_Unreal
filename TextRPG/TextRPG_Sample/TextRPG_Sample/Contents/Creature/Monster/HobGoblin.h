#pragma once

struct AggroList
{
	AggroList(Creature* player) : _player(player), _dmgAmount(0) {}

	Creature* _player;
	int _dmgAmount;
};

class HobGoblin : public Monster
{
public:
	HobGoblin(string name, int hp, int mp, int atk, int exp);
	virtual ~HobGoblin();

	virtual void Attack(Creature* other) override;
	virtual void TakeDamage(Creature* other, int amount) override;

	virtual int GiveExp() override;

	virtual void Recovery() override;

	void Set_PList(Creature* player);

	void Set_AggroList(vector<Creature*> player);
	void Modify_AggroList(vector<Creature*> player, int amount);
	void Sort_AggroList();


private:
	vector<AggroList> _aggroList;
	vector<Creature*> _pList;
};


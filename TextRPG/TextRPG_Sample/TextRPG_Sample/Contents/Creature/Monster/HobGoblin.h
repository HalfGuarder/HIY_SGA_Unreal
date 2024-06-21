#pragma once
struct P_Key
{
	P_Key(vector<Creature*> pKey) : _pKey(pKey) {}

	vector<Creature*> _pKey;
};

struct DamageInfo
{
	DamageInfo(int damage) : _damage(damage) {}

	int _damage;
};

class HobGoblin : public Monster
{
public:
	HobGoblin(string name, int hp, int mp, int atk, int exp);
	virtual ~HobGoblin();

	virtual void Attack(Creature* other) override;

	virtual int GiveExp() override;

	virtual void Recovery() override;

	void Set_AggroList(vector<Creature*> player);
	void Modify_AggroList(vector<Creature*> player, int amount);
	void Sort_AggroList();


private:
	map<P_Key, DamageInfo> _aggroList;
};


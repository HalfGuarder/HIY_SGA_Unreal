#pragma once
class HobGoblin : public Monster
{
public:
	HobGoblin(string name, int hp, int mp, int atk, int exp);
	virtual ~HobGoblin();

	virtual void Attack(Creature* other) override;

	virtual int GiveExp() override;

	virtual void Recovery() override;
};


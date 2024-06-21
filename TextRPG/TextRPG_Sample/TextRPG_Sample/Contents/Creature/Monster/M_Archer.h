#pragma once
class M_Archer : public Monster
{
public:
	M_Archer(string name, int hp, int mp, int atk, int exp);
	virtual ~M_Archer();

	virtual void Attack(Creature* other) override;

	virtual int GiveExp() override;

	virtual void Recovery() override;
};


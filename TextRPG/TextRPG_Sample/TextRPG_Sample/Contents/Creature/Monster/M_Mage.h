#pragma once
class M_Mage : public Monster
{
public:
	M_Mage(string name, int hp, int mp, int atk, int exp);
	virtual ~M_Mage();

	virtual void Attack(Creature* other) override;

	virtual int GiveExp() override;

	virtual void Recovery() override;
};


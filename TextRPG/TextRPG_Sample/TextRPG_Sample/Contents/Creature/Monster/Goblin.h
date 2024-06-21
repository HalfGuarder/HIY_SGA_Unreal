#pragma once
class Goblin : public Monster
{
public:
	Goblin(string name, int hp, int mp, int atk, int exp);
	virtual ~Goblin();

	virtual void Attack(Creature* other) override;

	virtual int GiveExp() override;

	virtual void Recovery() override;

};


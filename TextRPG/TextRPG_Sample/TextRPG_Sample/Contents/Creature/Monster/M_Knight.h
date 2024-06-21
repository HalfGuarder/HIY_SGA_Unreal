#pragma once
class M_Knight : public Monster
{
public:
	M_Knight(string name, int hp, int mp, int atk, int exp);
	virtual ~M_Knight();

	virtual void Attack(Creature* other) override;

	virtual int GiveExp() override;

	virtual void Recovery() override;
};


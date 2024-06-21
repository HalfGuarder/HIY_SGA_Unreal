#pragma once
class Monster : public Creature
{
public:
	Monster(string name, int hp, int mp, int atk, int exp);
	virtual ~Monster();

	virtual int GiveExp() abstract;


protected:

};


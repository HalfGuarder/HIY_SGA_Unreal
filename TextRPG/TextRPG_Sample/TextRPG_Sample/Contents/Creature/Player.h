#pragma once
class Player : public Creature
{
public:
	Player(string name, int hp, int mp, int atk, int exp);
	virtual ~Player();

	virtual void TakeExp(Monster* monster) abstract;

	

protected:
	//int _exp;
};


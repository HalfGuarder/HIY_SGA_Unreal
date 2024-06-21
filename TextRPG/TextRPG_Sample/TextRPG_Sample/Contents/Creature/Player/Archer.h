#pragma once
class Archer : public Player
{
public:
	Archer(string name, int hp, int mp, int atk, int exp);
	virtual ~Archer();

	// Player을(를) 통해 상속됨
	virtual void Attack(Creature* other) override;

	virtual void TakeExp(Monster* monster) override;

	virtual void Recovery() override;


private:

};


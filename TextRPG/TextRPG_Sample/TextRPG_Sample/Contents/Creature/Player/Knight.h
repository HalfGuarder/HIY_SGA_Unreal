#pragma once
class Knight : public Player
{
public:
	Knight(string name, int hp, int mp, int atk, int exp);
	virtual ~Knight();

	// Player을(를) 통해 상속됨
	virtual void Attack(Creature* other) override;

	virtual void TakeExp(Monster* monster) override;

	virtual void Recovery() override;


private:

	
};


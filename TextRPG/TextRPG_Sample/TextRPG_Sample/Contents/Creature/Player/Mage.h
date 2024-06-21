#pragma once
class Mage : public Player
{
public:
	Mage(string name, int hp, int mp, int atk, int exp);
	virtual ~Mage();

	// Player를 통해 상속
	virtual void Attack(Creature* other) override;

	virtual void TakeExp(Monster* monster) override;

	virtual void Recovery() override;


	virtual int ReturnHpStat() override;
	virtual int ReturnMpStat() override;
	virtual int ReturnAtkStat() override;

private:

};


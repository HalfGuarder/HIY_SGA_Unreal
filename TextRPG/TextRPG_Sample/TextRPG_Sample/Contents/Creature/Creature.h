#pragma once
class Monster;
class Creature
{
public:
	Creature(string name, int hp, int mp, int atk, int exp);
	virtual ~Creature();

	// 멤버 함수 : 기능
	void PrintInfo();
	void PreAttack(Creature* other);
	virtual void Attack(Creature* other = nullptr) abstract; // 순수 가상 함수
	virtual void TakeDamage(int amount, Creature* attacker = nullptr);

	virtual void Recovery() abstract;

	bool IsDead() { return _curHp <= 0; }



protected: // 멤버 변수 : 속성
	string _name;
	int _curHp;
	int _maxHp;
	int _curMp;
	int _maxMp;
	int _atk;
	int _exp;
};


#pragma once
class World
{
public:
	enum PlayerType
	{
		NONE = 0,
		KNIGHT = 1,
		ARCHER = 2,
		MAGE = 3
	};

	enum Road
	{
		NONEROAD = 0,
		HUNT = 1,
		BATTLE = 2,
		BOSS = 3
	};

	World();
	~World();
	// 깊은 복사 : 복사 생성자, 복사 대입 연산자 둘 다
	// 복사 생성자
	// World(const World& other);
	// 복사 대입 연산자
	// World& operator=(const World& other); // 구현 필요


	void Init(); // 초기화
	bool ChooseRoad();

		
	// 어떤 배틀을 할지 선택
	void Battle1();
	void Battle2();
	
	bool Battle1End();
	bool Battle2End();

	bool GameEnd();

	// bool BossChallenge();


private:
	bool SelectPlayer(int num, string name, Creature** creature);
	bool SelectComputer(int num, string name, Creature** creature);
	void Input();

	void SetG_Arr(int size);
	string G_ArrName(int num);
	void ArrBattle(Creature* p, vector<Creature*> arr);
	bool ArrIsDead(vector<Creature*> arr);
	void DeleteArr();



	
	vector<Creature*>::iterator gArrIter = _gArr.begin();
	Creature* _player;
	Creature* _computer;
	vector<Creature*> _gArr;
};


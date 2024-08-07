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
	int ChooseRoad();

		
	// 어떤 배틀을 할지 선택
	void Battle1();
	void Battle2();
	void Battle3();
	
	bool Battle1End();
	bool Battle2End();
	bool Battle3End();

	bool GameEnd();

	// bool BossChallenge();


private:
	bool SelectPlayer(int num, string name, shared_ptr<Creature*> creature);
	bool SelectComputer(int num, string name, Creature** creature);
	void Input();

	void Set_GArr(int size);
	string GArrName(int num);
	void ArrBattle(Creature* p, vector<Creature*> arr);
	bool ArrIsDead(vector<Creature*> arr);
	void DeleteArr(vector<Creature*> arr);

	void Set_HGoblin(Creature** creature);

	void Set_PArr(int size);
	string PArrName(int pClass, int num);

	
	//vector<Creature*>::iterator gArrIter = _gArr.begin();
	shared_ptr<Creature> _player;
	Creature* _computer;
	vector<shared_ptr<Creature>> _gArr;

	Creature* _hGoblin = nullptr;
	vector<Creature*> _pArr;
};


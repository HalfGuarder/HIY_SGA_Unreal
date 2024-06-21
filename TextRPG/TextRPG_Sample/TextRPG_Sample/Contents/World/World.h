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
	// ���� ���� : ���� ������, ���� ���� ������ �� ��
	// ���� ������
	// World(const World& other);
	// ���� ���� ������
	// World& operator=(const World& other); // ���� �ʿ�


	void Init(); // �ʱ�ȭ
	bool ChooseRoad();

		
	// � ��Ʋ�� ���� ����
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


#include "pch.h"
#include "World.h"

World::World()
	:_player(nullptr),
	_computer(nullptr), // 벡터는 초기화 필요 없음
	_hGoblin(nullptr)

{
	Input();

	// 고블린 생성

	Init(); // 크리처에서도 구현
}

World::~World()
{
	DeleteArr(_pArr);

	if (_hGoblin != nullptr)
		delete _hGoblin;

	DeleteArr(_gArr);

	if(_computer != nullptr)
		delete _computer;
	if(_player != nullptr)
		delete _player;
}

void World::Init()
{
	_player->Recovery();
	_computer->Recovery();
	if (_hGoblin != nullptr)
	{
		_hGoblin->Recovery();
	}

	// 체력 등을 다시 세팅
}

int World::ChooseRoad() // bool 유형으로 하면 세 가지를 못 고름 다른 자료형으로 교체 필요
{
	int road;

	if (_hGoblin == nullptr)
	{
		while (true)
		{
			cout << "1. 사냥 / 2. 대결 중 원하시는 길을 고르세요." << endl;
			cin >> road;

			switch (road)
			{
			case Road::NONEROAD:
			{
				cout << "다시 입력해 주세요." << endl;
				continue;
			}

			case Road::HUNT:
			{
				Init();
				cout << "사냥을 선택하셨습니다." << endl;
				return HUNT;
			}

			case Road::BATTLE:
			{
				Init();
				cout << "대결을 선택하셨습니다." << endl;
				return BATTLE;
			}

			default:
			{
				cout << "다시 입력해 주세요." << endl;
				continue;
			}
			break;
			}
		}
	}
	else
	{
		while (true)
		{
			cout << "1. 사냥 / 2. 대결 / 3. 보스 중 원하시는 길을 고르세요." << endl;
			cin >> road;

			switch (road)
			{
			case Road::NONEROAD:
			{
				cout << "다시 입력해 주세요." << endl;
				continue;
			}

			case Road::HUNT:
			{
				cout << "사냥을 선택하셨습니다." << endl;
				return HUNT;
			}

			case Road::BATTLE:
			{
				cout << "대결을 선택하셨습니다." << endl;
				return BATTLE;
			}

			case Road::BOSS:
			{
				cout << "보스를 선택하셨습니다." << endl;
				return BOSS;
			}

			default:
			{
				cout << "다시 입력해 주세요." << endl;
				continue;
			}
			break;
			}
		}
	}
}

bool World::Battle1End()
{
	if (_player->IsDead() || ArrIsDead(_gArr))
	{
		cout << "사냥 종료." << endl;
		return true;
	}

	return false;
	
}

bool World::Battle2End()
{
	if (_player->IsDead())
	{
		cout << "---대결 패배---" << endl;

		return true;
	}
	else if (_computer->IsDead())
	{
		_player->PrintInfo();

		cout << "---대결 승리---" << endl;
		return true;
	}

	return false;
}

bool World::Battle3End()
{

	if (ArrIsDead(_pArr))
	{
		cout << "전원 사망." << endl;
		return true;
	}
	else if (_hGoblin->IsDead())
	{
		cout << "보스 사망." << endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool World::GameEnd()
{
	if (_hGoblin == nullptr)
	{
		return false;
	}
	else
	{
		if (_hGoblin->IsDead())
		{
			return true;
		}
	}

	return false;
}

bool World::SelectPlayer(int num, string name, Creature** creature)
{
		switch (num)
		{
		case PlayerType::NONE:
		{
			cout << "다시 입력해 주세요." << endl;
			return false;
		}

		case PlayerType::KNIGHT:
		{
			*creature = new Knight(name, 400, 0, 15, 0);
			cout << "기사를 선택하셨습니다." << endl;
			return true;
		}

		case PlayerType::ARCHER:
		{
			*creature = new Archer(name, 300, 0, 25, 0);
			cout << "궁수를 선택하셨습니다." << endl;
			return true;
		}
		
		case PlayerType::MAGE:
		{
			*creature = new Mage(name, 100, 30, 40, 0);
			cout << "마법사를 선택하셨습니다." << endl;
			return true;
		}

		default:
		{
			cout << "다시 입력해 주세요." << endl;
			return false;
		}
		break;
		}
}

bool World::SelectComputer(int num, string name, Creature** creature)
{
	switch (num)
	{
	case PlayerType::NONE:
	{
		cout << "다시 입력해 주세요." << endl;
		return false;
	}

	case PlayerType::KNIGHT:
	{
		*creature = new M_Knight(name, 1500, 0, 25, 100);
		return true;
	}

	case PlayerType::ARCHER:
	{
		*creature = new M_Archer(name, 900, 0, 30, 100);
		return true;
	}

	case PlayerType::MAGE:
	{
		*creature = new M_Mage(name, 700, 50, 50, 100);
		return true;
	}

	default:
	{
		cout << "다시 입력해 주세요." << endl;
		return false;
	}
	break;
	}
}

void World::Input()
{
	int playerNum = 0;
	int cumNum = 0;
	string name;

	bool select;

	cout << "이름을 입력해 주세요." << endl;
	cin >> name;

	while (true)
	{
		cout << "1 ~ 3까지의 클래스를 입력해 주세요" << endl;
		cin >> playerNum;
		cumNum = rand() % 3 + 1; // 1 ~ 3
		select = SelectPlayer(playerNum, name, &_player);
		if (!select)
		{
			continue;
		}
		SelectComputer(cumNum, "computer", &_computer);
		break;
	}
}

void World::Set_GArr(int size)
{
	if (_gArr.size() == 0)
	{
		for (int i = 0; i < size; i++)
		{
			string gName = GArrName(i);
			int gHp = rand() % 21 + 40; // 40 ~ 60
			int gAtk = rand() % 6 + 5; // 5 ~ 10
			_gArr.push_back(new Goblin(gName, gHp, 0, gAtk, 10));
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			string gName = GArrName(i);
			int gHp = rand() % 21 + 40; // 40 ~ 60
			int gAtk = rand() % 6 + 5; // 5 ~ 10
			_gArr.at(i) = new Goblin(gName, gHp, 0, gAtk, 10);
		}
	}
}

string World::GArrName(int num)
{
	string count = to_string(num + 1);
	string name = "고블린 ";
	name += count; name += "호";

	return name;
}

void World::ArrBattle(Creature* p, vector<Creature*> arr) // gArr가 world에 있기 때문에 arr를 매개 변수로 받지 않아도 사용 가능 ... 수정 필요
{
	for (int i = 0; i < arr.size(); i++)
	{
		p->Attack(arr.at(i));
		arr[i]->Attack(p);
	}
}

bool World::ArrIsDead(vector<Creature*> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (!arr.at(i)->IsDead())
			return false;
	}

	return true;
}

void World::DeleteArr(vector<Creature*> arr)
{
	for (int i = arr.size() - 1; i >= 0; i--)
	{
		if (arr.at(i) != nullptr)
		{
			arr.erase(arr.end() - 1);
		}
	}
}

void World::Set_HGoblin(Creature** creature)
{
	*creature = new HobGoblin("호브호브 고블린", 5000, 1000, 300, 5000);
}

void World::Set_PArr(int size)
{
	Player* stats = dynamic_cast<Player*>(_player);

	if (_pArr.size() == 0)
	{
		_pArr.push_back(_player);

		for (int i = 1; i < size; i++)
		{
			int pClass = rand() % 3 + 1;
			int ranStat = rand() % 10;
			
			if (pClass == KNIGHT)
			{
				string pName = PArrName(KNIGHT, i);
				int pHp = (stats->ReturnHpStat()) * 1.2 + ranStat;
				int pMp = stats->ReturnMpStat();
				int pAtk = (stats->ReturnAtkStat()) * 0.5 + ranStat;

				_pArr.push_back(new Knight(pName, pHp, pMp, pAtk, 0));
			}

			else if (pClass == ARCHER)
			{
				string pName = PArrName(ARCHER, i);
				int pHp = (stats->ReturnHpStat()) * 0.5 + ranStat;
				int pMp = stats->ReturnMpStat();
				int pAtk = (stats->ReturnAtkStat()) * 0.7 + ranStat;

				_pArr.push_back(new Archer(pName, pHp, pMp, pAtk, 0));
			}
			else if (pClass == MAGE)
			{
				string pName = PArrName(MAGE, i);
				int pHp = stats->ReturnHpStat();
				int pMp = (stats->ReturnMpStat()) * 0.8 + ranStat;
				int pAtk = (stats->ReturnAtkStat()) * 0.8 + ranStat;

				_pArr.push_back(new Mage(pName, pHp, pMp, pAtk, 0));
			}
			
		}
	}
	else
	{
		for (int i = 1; i < size; i++)
		{
			int pClass = rand() % 3 + 1;
			int ranStat = rand() % 10;

			if (pClass == KNIGHT)
			{
				string pName = PArrName(KNIGHT, i);
				int pHp = stats->ReturnHpStat() * 1.2 + ranStat;
				int pMp = stats->ReturnMpStat();
				int pAtk = stats->ReturnAtkStat() * 0.5 + ranStat;

				_pArr.at(i) = (new Knight(pName, pHp, pMp, pAtk, 0));
			}

			else if (pClass == ARCHER)
			{
				string pName = PArrName(ARCHER, i);
				int pHp = stats->ReturnHpStat() * 0.5 + ranStat;
				int pMp = stats->ReturnMpStat();
				int pAtk = stats->ReturnAtkStat() * 0.7 + ranStat;

				_pArr.at(i) = (new Archer(pName, pHp, pMp, pAtk, 0));
			}
			else if (pClass == MAGE)
			{
				string pName = PArrName(MAGE, i);
				int pHp = stats->ReturnHpStat();
				int pMp = stats->ReturnMpStat() * 0.8 + ranStat;
				int pAtk = stats->ReturnAtkStat() * 0.8 + ranStat;

				_pArr.at(i) = (new Mage(pName, pHp, pMp, pAtk, 0));
			}

		}
	}
}

string World::PArrName(int pClass, int num)
{
	string returnName;

	if (pClass == KNIGHT)
	{
		string count = to_string(num);
		string name = "파티원 ";
		name += count; name += "호 - 기사";
		returnName = name;
	}
	else if (pClass == ARCHER)
	{
		string count = to_string(num);
		string name = "파티원 ";
		name += count; name += "호 - 궁수";
		returnName = name;
	}
	else if (pClass == MAGE)
	{
		string count = to_string(num);
		string name = "파티원 ";
		name += count; name += "호 - 마법사";
		returnName = name;
	}

	return returnName;
}

void World::Battle1()
{
	Init();
	Set_GArr(10);

	while (true)
	{
		ArrBattle(_player, _gArr);

		if (Battle1End())
		{
			break;
		}
	}
}

void World::Battle2()
{	
	Init();

	while (true)
	{
		_player->Attack(_computer);
		_computer->Attack(_player);

		if (Battle2End())
		{
			Set_HGoblin(&_hGoblin);
			break;
		}
	}
}

void World::Battle3()
{
	Init();

	Set_PArr(10);

	for (int i = 0; i < _pArr.size(); i++)
	{
		_pArr[i]->PrintInfo();
	}

	_hGoblin->PrintInfo();

	while (true)
	{
		for (int i = 0; i < _pArr.size(); i++)
		{
			_pArr[i]->Attack(_hGoblin);
		}
		_hGoblin->Attack();

		if (Battle3End())
		{
			break;
		}

	}
}


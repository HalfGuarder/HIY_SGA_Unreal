#include "pch.h"
#include "World.h"

World::World()
	:_player(nullptr),
	_computer(nullptr) // 벡터는 초기화 필요 없음

{
	Input();

	// 고블린 생성

	Init(); // 크리처에서도 구현
}

World::~World()
{
	if(_computer != nullptr)
		delete _computer;
	if(_player != nullptr)
		delete _player;

	// 고블린 제거
	DeleteArr();
}

void World::Init()
{
	// 체력 등을 다시 세팅
}

bool World::ChooseRoad() // bool 유형으로 하면 세 가지를 못 고름 다른 자료형으로 교체 필요
{
	int road;

	if (!BossChallenge())
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
				cout << "사냥을 선택하셨습니다." << endl;
				return true;
			}

			case Road::BATTLE:
			{
				cout << "대결을 선택하셨습니다." << endl;
				return false;
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
				return true;
			}

			case Road::BATTLE:
			{
				cout << "대결을 선택하셨습니다." << endl;
				return false;
			}

			case Road::BOSS:
			{
				cout << "보스를 선택하셨습니다." << endl;
				return false;
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
	if (_player->IsDead())
	{
		cout << "---대결 패배---" << endl;
		_player->Recovery();
		_computer->Recovery();
		return true;
	}
	else if (_computer->IsDead())
	{
		_player->Recovery();
		_player->PrintInfo();
		cout << "---대결 승리---" << endl;
		return true;
	}

	return false;
}

bool World::Battle2End()
{
	if (_player->IsDead() || ArrIsDead(_gArr))
	{
		cout << "사냥 종료." << endl;
		return true;
	}

	return false;
}

bool World::GameEnd()
{
	if (_computer->IsDead())
	{
		return true;
	}

	return false;
}

/*bool World::BossChallenge() // IsDead랑 중복 ... 주석 처리
{
	if (_computer->IsDead())
	{
		return true;
	}

	return false;
}*/

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

void World::SetG_Arr(int size)
{
	if (_gArr.size() == 0)
	{
		for (int i = 0; i < size; i++)
		{
			string gName = G_ArrName(i);
			int gHp = rand() % 21 + 40; // 40 ~ 60
			int gAtk = rand() % 6 + 5; // 5 ~ 10
			_gArr.push_back(new Goblin(gName, gHp, 0, gAtk, 10));
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			string gName = G_ArrName(i);
			int gHp = rand() % 21 + 40; // 40 ~ 60
			int gAtk = rand() % 6 + 5; // 5 ~ 10
			_gArr.at(i) = new Goblin(gName, gHp, 0, gAtk, 10);
		}
	}
}

string World::G_ArrName(int num)
{
	string count = to_string(num + 1);
	string name = "고블린 ";
	name += count; name += "호";

	return name;
}

void World::ArrBattle(Creature* p, vector<Creature*> arr)
{

	while (true)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			p->Attack(arr.at(i));
			arr[i]->Attack(p);

			if (p->IsDead())
			{
				return;
			}
		}

		if (ArrIsDead(arr))
		{
			return;
		}
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

void World::DeleteArr()
{
	for (int i = _gArr.size() - 1; i >= 0; i--)
	{
		if (_gArr.at(i) != nullptr)
		{
			_gArr.erase(_gArr.end() - 1); // erase? 어떤 방식으로 삭제?
		}
	}
}



void World::Battle1()
{
	_player->Attack(_computer);
	_computer->Attack(_player);
}

void World::Battle2()
{	
	SetG_Arr(10);
	
	ArrBattle(_player, _gArr);

	_player->Recovery();
}




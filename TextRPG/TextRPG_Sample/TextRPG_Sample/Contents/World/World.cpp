#include "pch.h"
#include "World.h"

World::World()
	:_player(nullptr),
	_computer(nullptr) // ���ʹ� �ʱ�ȭ �ʿ� ����

{
	Input();

	// ��� ����

	Init(); // ũ��ó������ ����
}

World::~World()
{
	if(_computer != nullptr)
		delete _computer;
	if(_player != nullptr)
		delete _player;

	// ��� ����
	DeleteArr();
}

void World::Init()
{
	// ü�� ���� �ٽ� ����
}

bool World::ChooseRoad() // bool �������� �ϸ� �� ������ �� �� �ٸ� �ڷ������� ��ü �ʿ�
{
	int road;

	if (!BossChallenge())
	{
		while (true)
		{
			cout << "1. ��� / 2. ��� �� ���Ͻô� ���� ������." << endl;
			cin >> road;

			switch (road)
			{
			case Road::NONEROAD:
			{
				cout << "�ٽ� �Է��� �ּ���." << endl;
				continue;
			}

			case Road::HUNT:
			{
				cout << "����� �����ϼ̽��ϴ�." << endl;
				return true;
			}

			case Road::BATTLE:
			{
				cout << "����� �����ϼ̽��ϴ�." << endl;
				return false;
			}

			default:
			{
				cout << "�ٽ� �Է��� �ּ���." << endl;
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
			cout << "1. ��� / 2. ��� / 3. ���� �� ���Ͻô� ���� ������." << endl;
			cin >> road;

			switch (road)
			{
			case Road::NONEROAD:
			{
				cout << "�ٽ� �Է��� �ּ���." << endl;
				continue;
			}

			case Road::HUNT:
			{
				cout << "����� �����ϼ̽��ϴ�." << endl;
				return true;
			}

			case Road::BATTLE:
			{
				cout << "����� �����ϼ̽��ϴ�." << endl;
				return false;
			}

			case Road::BOSS:
			{
				cout << "������ �����ϼ̽��ϴ�." << endl;
				return false;
			}

			default:
			{
				cout << "�ٽ� �Է��� �ּ���." << endl;
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
		cout << "---��� �й�---" << endl;
		_player->Recovery();
		_computer->Recovery();
		return true;
	}
	else if (_computer->IsDead())
	{
		_player->Recovery();
		_player->PrintInfo();
		cout << "---��� �¸�---" << endl;
		return true;
	}

	return false;
}

bool World::Battle2End()
{
	if (_player->IsDead() || ArrIsDead(_gArr))
	{
		cout << "��� ����." << endl;
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

/*bool World::BossChallenge() // IsDead�� �ߺ� ... �ּ� ó��
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
			cout << "�ٽ� �Է��� �ּ���." << endl;
			return false;
		}

		case PlayerType::KNIGHT:
		{
			*creature = new Knight(name, 400, 0, 15, 0);
			cout << "��縦 �����ϼ̽��ϴ�." << endl;
			return true;
		}

		case PlayerType::ARCHER:
		{
			*creature = new Archer(name, 300, 0, 25, 0);
			cout << "�ü��� �����ϼ̽��ϴ�." << endl;
			return true;
		}
		
		case PlayerType::MAGE:
		{
			*creature = new Mage(name, 100, 30, 40, 0);
			cout << "�����縦 �����ϼ̽��ϴ�." << endl;
			return true;
		}

		default:
		{
			cout << "�ٽ� �Է��� �ּ���." << endl;
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
		cout << "�ٽ� �Է��� �ּ���." << endl;
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
		cout << "�ٽ� �Է��� �ּ���." << endl;
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

	cout << "�̸��� �Է��� �ּ���." << endl;
	cin >> name;

	while (true)
	{
		cout << "1 ~ 3������ Ŭ������ �Է��� �ּ���" << endl;
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
	string name = "��� ";
	name += count; name += "ȣ";

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
			_gArr.erase(_gArr.end() - 1); // erase? � ������� ����?
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




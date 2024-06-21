#include "pch.h"
#include "World.h"

World::World()
	:_player(nullptr),
	_computer(nullptr), // ���ʹ� �ʱ�ȭ �ʿ� ����
	_hGoblin(nullptr)

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
	_player->Recovery();
	_computer->Recovery();
	if (_hGoblin != nullptr)
	{
		_hGoblin->Recovery();
	}

	// ü�� ���� �ٽ� ����
}

int World::ChooseRoad() // bool �������� �ϸ� �� ������ �� �� �ٸ� �ڷ������� ��ü �ʿ�
{
	int road;

	if (!_computer->IsDead())
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
				Init();
				cout << "����� �����ϼ̽��ϴ�." << endl;
				return HUNT;
			}

			case Road::BATTLE:
			{
				Init();
				cout << "����� �����ϼ̽��ϴ�." << endl;
				return BATTLE;
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
				Init();
				cout << "����� �����ϼ̽��ϴ�." << endl;
				return HUNT;
			}

			case Road::BATTLE:
			{
				Init();
				cout << "����� �����ϼ̽��ϴ�." << endl;
				return BATTLE;
			}

			case Road::BOSS:
			{
				Init();
				cout << "������ �����ϼ̽��ϴ�." << endl;
				return BOSS;
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
		//_player->Recovery();
		//_computer->Recovery();
		return true;
	}
	else if (_computer->IsDead())
	{
		//_player->Recovery();
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

bool World::Battle3End()
{
	if (_player->IsDead() || _hGoblin->IsDead())
	{
		cout << "���� ���." << endl;
		return true;
	}

	return false;
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
	string name = "��� ";
	name += count; name += "ȣ";

	return name;
}

void World::ArrBattle(Creature* p, vector<Creature*> arr) // gArr�� world�� �ֱ� ������ arr�� �Ű� ������ ���� �ʾƵ� ��� ���� ... ���� �ʿ�
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

void World::Set_HGoblin(Creature** creature)
{
	*creature = new HobGoblin("ȣ��ȣ�� ���", 0, 1000, 100, 5000);
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
			
			if (pClass == KNIGHT)
			{
				string pName = PArrName(KNIGHT, i);
				int pHp = (stats->ReturnHpStat()) * 1.2;
				int pMp = stats->ReturnMpStat();
				int pAtk = (stats->ReturnAtkStat()) * 0.5;

				_pArr.push_back(new Knight(pName, pHp, pMp, pAtk, 0));
			}

			else if (pClass == ARCHER)
			{
				string pName = PArrName(ARCHER, i);
				int pHp = (stats->ReturnHpStat()) * 0.5;
				int pMp = stats->ReturnMpStat();
				int pAtk = (stats->ReturnAtkStat()) * 0.7;

				_pArr.push_back(new Archer(pName, pHp, pMp, pAtk, 0));
			}
			else if (pClass == MAGE)
			{
				string pName = PArrName(MAGE, i);
				int pHp = stats->ReturnHpStat();
				int pMp = (stats->ReturnMpStat()) * 0.8;
				int pAtk = (stats->ReturnAtkStat()) * 0.8;

				_pArr.push_back(new Mage(pName, pHp, pMp, pAtk, 0));
			}
			
		}
	}
	else
	{
		//_pArr.at(0) = _player;

		for (int i = 1; i < size; i++)
		{
			int pClass = rand() % 3 + 1;

			if (pClass == KNIGHT)
			{
				string pName = PArrName(KNIGHT, i);
				int pHp = stats->ReturnHpStat();
				int pMp = stats->ReturnMpStat();
				int pAtk = stats->ReturnAtkStat();

				_pArr.at(i) = (new Knight(pName, pHp, pMp, pAtk, 0));
			}

			else if (pClass == ARCHER)
			{
				string pName = PArrName(ARCHER, i);
				int pHp = stats->ReturnHpStat();
				int pMp = stats->ReturnMpStat();
				int pAtk = stats->ReturnAtkStat();

				_pArr.at(i) = (new Archer(pName, pHp, pMp, pAtk, 0));
			}
			else if (pClass == MAGE)
			{
				string pName = PArrName(MAGE, i);
				int pHp = stats->ReturnHpStat();
				int pMp = stats->ReturnMpStat();
				int pAtk = stats->ReturnAtkStat();

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
		string name = "��Ƽ�� ";
		name += count; name += "ȣ - ���";
		returnName = name;
	}
	else if (pClass == ARCHER)
	{
		string count = to_string(num);
		string name = "��Ƽ�� ";
		name += count; name += "ȣ - �ü�";
		returnName = name;
	}
	else if (pClass == MAGE)
	{
		string count = to_string(num);
		string name = "��Ƽ�� ";
		name += count; name += "ȣ - ������";
		returnName = name;
	}

	return returnName;
}

void World::Battle1()
{
	_player->Attack(_computer);
	_computer->Attack(_player);
}

void World::Battle2()
{	
	Set_GArr(10);
	
	ArrBattle(_player, _gArr);

	//_player->Recovery();
}

void World::Battle3()
{
	Set_PArr(10);
	for (int i = 0; i < _pArr.size(); i++)
	{
		_pArr[i]->PrintInfo();
	}
	Set_HGoblin(&_hGoblin);
	_hGoblin->PrintInfo();
}


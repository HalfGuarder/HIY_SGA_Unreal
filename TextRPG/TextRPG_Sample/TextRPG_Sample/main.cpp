// �ֻ��� Ŭ���� Creature ... �߻� Ŭ����
// - Player
// -- Knight
// -- Archer
// -- Mage
// - Monster

// ��缭1
// 1. 1~3�� ���� �Է¹޾Ƽ� Knight, Archer, Mage �� ���� �� �ϳ��� ������ ����(�����Ҵ�)�ϰ� ���ּ���.
// 2. ��ǻ�͵� ������ �޾Ƽ� 1.�� ���� �������ּ���.
// 3. �÷��̾��� �̸��� �Է¹ް� Set���ּ���. ��ǻ�ʹ� ��ǻ�ͷ�
// 4. ������ �� ������ �̸��� ǥ�õǰ����ּ���. ��) Hanil�� ��ǻ�͸� �����߽��ϴ�.
// 5. Knight�� ü���� 50���� �̸��� �Ǹ� ���ݷ��� 2�� �������ϴ�.
// 6. Mage�� ������ 5��ŭ �Һ��Ͽ� ������ �մϴ�. ������ �� ������ �����ϴٸ� 50��ŭ ȸ���ϰ� ������ ���ϴ�.
// 7. Archer 30���� Ȯ���� ũ��Ƽ�� ������(3�� ����)�� �մϴ�.
// 8. �� �� ���� �̱���� üũ�ϰ� �̱� �� ���� �ݺ�

// ��缭2
// 0. ��ǻ�Ϳ� �������� ������� ����ġ�� ������ 1,2 �Է����� ����(��ǻ�Ϳ� ���� �й�� Ȥ�� �������� ���� ��)
// 1. Creature ��ӹ޴� Player ����ϴ�.
// 2. ��缭1�� Knight�� Archer, Mage�� Player�� ��ӹ޽��ϴ�. �� �� Player�� �߻�Ŭ�����Դϴ�.
// 3. Player�� �Ӽ����� ����ġ�� �߰��˴ϴ�.
// 4. Player�� ������ 10������ �ο�� �������� ����ġ�� ��� ����ġ�� ���� ������ �ö󰩴ϴ�.
// 5. ������ ������ ��缭1�� ������ �ٽ��ؼ� �̱�� ���α׷� ����

#include "pch.h"

enum Road
{
	HUNT = 1,
	BATTLE = 2,
	BOSS = 3
};

int main()
{
	srand(time(nullptr));

	World* world = new World();

	while (true)
	{
		int road = world->ChooseRoad();

		if (road == HUNT)
		{
			while (true)
			{
				world->Battle2();

				if (world->Battle2End())
					break;
			}
		}
		else if (road == BATTLE)
		{
			while (true)
			{
				world->Battle1();

				if (world->Battle1End())
					break;
			}
		}
		else if (road == BOSS)
		{
			while (true)
			{
				cout << "������ ����" << endl;
				world->Battle3();

				if (world->Battle3End())
					break;
			}
		}

		if (world->GameEnd())
		{
			break;
		}
	}
	

	delete world;



	return 0;
}
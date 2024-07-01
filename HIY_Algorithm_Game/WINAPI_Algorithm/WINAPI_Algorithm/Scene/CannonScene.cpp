#include "pch.h"
#include "CannonScene.h"
#include "Objects/Cannon.h"
#include "Objects/Bullet.h"

// ��缭
// ���� ��Ʈ����
// �� cannon�� �ϸ��� ���� ��Ʈ���� �޾Ƽ� ���� (cannon �� ��)
// cannon�� HP�� 5
// ������ HP -1, HP�� 0�̸� �ش� ĳ���� �����


CannonScene::CannonScene()
{
	_cannon1 = make_shared<Cannon>();
	_cannon2 = make_shared<Cannon>();

	_cannon1->_isShot = false;
	
	// Attack2
	for (auto bullet : _cannon1->GetBullets())
	{
		bullet->SetTarget(_cannon2);
	}

	for (auto bullet : _cannon2->GetBullets())
	{
		bullet->SetTarget(_cannon1);
	}
}

CannonScene::~CannonScene()
{
}

void CannonScene::Update()
{
	_cannon1->Update();
	_cannon2->Update();




	// Attack 1
	//for (auto bullet : _cannon1->GetBullets())
	//{
		//bullet->Attack_Cannon(_cannon2);
	//}
}

void CannonScene::Render(HDC hdc)
{
	_cannon1->Render(hdc);
	_cannon2->Render(hdc);
}

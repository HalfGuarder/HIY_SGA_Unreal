#include "pch.h"
#include "CannonScene.h"
#include "Objects/Cannon.h"
#include "Objects/Bullet.h"

// 사양서
// 턴제 포트리스
// 각 cannon은 턴마다 서로 컨트롤을 받아서 공격 (cannon 두 개)
// cannon의 HP는 5
// 맞으면 HP -1, HP가 0이면 해당 캐논이 사라짐


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

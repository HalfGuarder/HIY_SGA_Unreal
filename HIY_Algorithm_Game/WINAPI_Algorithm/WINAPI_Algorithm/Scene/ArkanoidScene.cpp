#include "pch.h"
#include "ArkanoidScene.h"

#include "Objects\Arkanoid\Map.h"
#include "Objects\Arkanoid\Bar.h"
#include "Objects\Arkanoid\Ball.h"
#include "Objects\Arkanoid\A_Block.h"

ArkanoidScene::ArkanoidScene()
{
	_map = make_shared<Map>();
	_bar = make_shared<Bar>();
	_ball = make_shared<Ball>();

	//_ball->OnStart(_map->GetSingleBlock(49, 14)->_center + Vector2(0, 30), Vector2(0, -1));
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_map->Update();
	_bar->Update();

	_ball->Update();

	//_ball->Bounce(_map, _bar, _map->GetBlocks(), _map->GetFences());
}

void ArkanoidScene::Render(HDC hdc)
{
	wstring temp = L"Hello Arkanoid!!!";
	TextOut(hdc, CENTER._x - 500, 100, temp.c_str(), temp.size());

	_map->Render(hdc);
	_bar->Render(hdc);
	_ball->Render(hdc);
}

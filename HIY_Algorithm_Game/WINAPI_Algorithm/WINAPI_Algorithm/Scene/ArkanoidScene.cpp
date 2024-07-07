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

	_ball->OnStart();
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_map->Update();
	_bar->Update();

	_ball->Update();

	_ball->Bounce(_map, _bar, _map->GetBlocks(), _map->GetFences());
}

void ArkanoidScene::Render(HDC hdc)
{
	wstring temp = L"Hello Arkanoid!!!";
	TextOut(hdc, CENTER._x - 500, 100, temp.c_str(), temp.size());

	wstring tmpScore1 = L"Score : ";
	wstring tmpScore2 = _ball->CurScore();

	TextOut(hdc, CENTER._x - 500, 130, tmpScore1.c_str(), tmpScore1.size());
	TextOut(hdc, CENTER._x - 440, 130, tmpScore2.c_str(), tmpScore2.size());

	_map->Render(hdc);
	_bar->Render(hdc);
	_ball->Render(hdc);
}

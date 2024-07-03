#include "pch.h"
#include "ArkanoidScene.h"

#include "Objects\Arkanoid\Map.h"
#include "Objects\Arkanoid\Bar.h"

ArkanoidScene::ArkanoidScene()
{
	_map = make_shared<Map>();
	//_bar = make_shared<Bar>();
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_map->Update();
	//_bar->Update();
}

void ArkanoidScene::Render(HDC hdc)
{
	wstring temp = L"Hello Arkanoid!!!";
	TextOut(hdc, CENTER._x - 500, 100, temp.c_str(), temp.size());

	_map->Render(hdc);
	//_bar->Render(hdc);
}

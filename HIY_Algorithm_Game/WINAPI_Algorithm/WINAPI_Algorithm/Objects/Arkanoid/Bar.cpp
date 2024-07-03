#include "pch.h"
#include "Bar.h"

Bar::Bar()
{
	_body = make_shared<RectCollider>(CENTER + Vector2(0, 350), Vector2(50, 20));
}

Bar::~Bar()
{
}

void Bar::Move()
{
	if (GetAsyncKeyState(VK_RIGHT))
	{
		_body->_center._x += 3.0f;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		_body->_center._x -= 3.0f;
	}
}

void Bar::Update()
{
	Move();
	_body->Update();
}

void Bar::Render(HDC hdc)
{
	_body->Render(hdc);
}

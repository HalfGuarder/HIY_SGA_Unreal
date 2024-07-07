#include "pch.h"
#include "A_Block.h"

A_Block::A_Block()
	:RectCollider(Vector2(), Vector2(10, 5))
{
	_brushes.push_back(CreateSolidBrush(BLACK));
	_brushes.push_back(CreateSolidBrush(GREEN));
	_brushes.push_back(CreateSolidBrush(RED));

	SetGreen();
}

A_Block::~A_Block()
{
	for (auto brush : _brushes)
	{
		DeleteObject(brush);
	}
}

void A_Block::Update()
{
	RectCollider::Update();
}

void A_Block::Render(HDC hdc)
{
	SelectObject(hdc, _brushes[static_cast<int>(_type)]);
	RectCollider::Render(hdc);
}

void A_Block::SetPositon(Vector2 pos)
{
	_center = pos;
}

void A_Block::SetBlockType(A_BlockType type)
{
	_type = type;
	switch (type)
	{
	case A_Block::A_BlockType::NONE:
	{
		SetBlack();
	}
		break;
	case A_Block::A_BlockType::DESTROY:
	{
		SetGreen();
	}
		break;
	case A_Block::A_BlockType::NONEDESTROY:
	{
		SetRed();
	}
		break;
	default:
		break;
	}
}


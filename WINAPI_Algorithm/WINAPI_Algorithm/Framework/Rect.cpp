#include "pch.h"
#include "Rect.h"

#include "Vector2.h"



RectCollider::RectCollider(Vector2 center, Vector2 halfSize)
	: _center(center), _halfSize(halfSize)
{
	_pens.push_back(CreatePen(PS_SOLID, 3, GREEN));
	_pens.push_back(CreatePen(PS_SOLID, 3, RED));

	SetColor(GREEN_COLOR);
}

RectCollider::~RectCollider()
{
	for (auto pen : _pens)
	{
		DeleteObject(pen);
	}
}

void RectCollider::Update()
{
	
}

void RectCollider::Render(HDC hdc)
{
	SelectObject(hdc, _curPen);

	int left = _center._x - _halfSize._x;
	int right = _center._x + _halfSize._x;
	int top = _center._y - _halfSize._y;
	int bottom = _center._y + _halfSize._y;

	Rectangle(hdc, left, top, right, bottom);
}

bool RectCollider::IsCollision(Vector2 point)
{
	// 포인트.x가 left, right 사이에 있나?
	if (point._x < Right() && point._x > Left())
	{
		if (point._y < Bottom() && point._y > Top())
		{
			return true;
		}
	}
	return false;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	return other->IsCollision(shared_from_this());
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{
	/*Vector2 leftTop = Vector2(Left(), Top());
	Vector2 rightTop = Vector2(Right(), Top());
	Vector2 leftBottom = Vector2(Left(), Bottom());
	Vector2 rightBottom = Vector2(Right(), Bottom());

	bool check1 = other->IsCollision(leftTop);
	bool check2 = other->IsCollision(leftTop);
	bool check3 = other->IsCollision(leftTop);
	bool check4 = other->IsCollision(leftTop);

	return check1 || check2 || check3 || check4;*/

	if (other->Top() < Bottom() && other->Bottom() > Top())
	{
		return (other->Left() < Right() && other->Left() >Left()) || (other->Right() > Left() && other->Right() < Right());
	}

	return false;
}

void RectCollider::SetColor(ColorNum index)
{
	_curPen = _pens[index];
}

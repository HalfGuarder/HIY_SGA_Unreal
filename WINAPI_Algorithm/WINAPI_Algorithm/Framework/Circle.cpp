#include "pch.h"
#include "Circle.h"


CircleCollider::CircleCollider(Vector2 center, float radius)
	: _center(center), _radius(radius)
{
	_pens.push_back(CreatePen(PS_SOLID, 3, GREEN));
	_pens.push_back(CreatePen(PS_SOLID, 3, RED));

	SetColor(GREEN_COLOR);
}

CircleCollider::~CircleCollider()
{
	for (auto pen : _pens)
	{
		DeleteObject(pen);
	}
}

void CircleCollider::Update()
{
}

void CircleCollider::Render(HDC hdc)
{
	SelectObject(hdc, _curPen);

	int left = _center._x - _radius;
	int top = _center._y - _radius;
	int right = _center._x + _radius;
	int bottom = _center._y + _radius;

	Ellipse(hdc, left, top, right, bottom);
}

bool CircleCollider::IsCollision(Vector2 point)
{
	float distance = _center.Distance(point);

	return distance < _radius;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	float distance = _center.Distance(other->_center);

	return distance < _radius + other->_radius;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> other)
{
	// 과제
	// AABB(회전하지 않는다는 조건)(WINAPI), OBB(회전이 가능)(WINAPI, DirectX) 충돌

	float distance = _center.Distance(other->_center);

	Vector2 Left = Vector2(_center._x - _radius, _center._y);
	Vector2 Right = Vector2(_center._x + _radius, _center._y);
	Vector2 Top = Vector2(_center._x, _center._y - _radius);
	Vector2 Bottom = Vector2(_center._x, _center._y + _radius);

	if (_radius + other->_halfSize.Length() < distance)
	{
		return false;
	}

	if (Left._x < other->Right() && Right._x > other->Left())
	{
		if (Bottom._y > other->Top() && Top._y < other->Bottom())
			return true;
	}


	return false;
}

void CircleCollider::SetColor(ColorNum index)
{
	_curPen = _pens[index];
}

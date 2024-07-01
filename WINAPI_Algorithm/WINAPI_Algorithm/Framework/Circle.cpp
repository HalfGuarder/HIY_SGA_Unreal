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

	/*Vector2 circleCenter = _center;
	float radius = _radius;

	Vector2 rectCenter = other->_center;
	Vector2 rectHalfSize = other->_halfSize;

	if (circleCenter._x < other->Right() && circleCenter._x > other->Left())
	{

		Vector2 newHalfSize = Vector2(rectHalfSize._x + radius, rectHalfSize._y + radius);
		RectCollider newRect = RectCollider(other->_center, newHalfSize);

		if (newRect.IsCollision(circleCenter))
			return true;

	}

	else if (circleCenter._y < other->Bottom() && circleCenter._y > other->Top())
	{
		Vector2 newHalfSize = Vector2(rectHalfSize._x + radius, rectHalfSize._y + radius);
		RectCollider newRect = RectCollider(other->_center, newHalfSize);

		if (newRect.IsCollision(circleCenter))
			return true;
	}

	else
	{
		bool check1 = IsCollision(Vector2(other->Left(), other->Top()));
		bool check2 = IsCollision(Vector2(other->Left(), other->Bottom()));
		bool check3 = IsCollision(Vector2(other->Right(), other->Top()));
		bool check4 = IsCollision(Vector2(other->Right(), other->Bottom()));

		return check1 || check2 || check3 || check4;
	}

	return false;*/
}

void CircleCollider::SetColor(ColorNum index)
{
	_curPen = _pens[index];
}

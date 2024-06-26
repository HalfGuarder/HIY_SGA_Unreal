#include "pch.h"
#include "Circle.h"

Circle::Circle(Vector2 center, Vector2 halfSize)
	: _center(center), _halfSize(halfSize)
{
}

void Circle::Update()
{
}

void Circle::Render(HDC hdc)
{
	int left = _center._x - _halfSize._x;
	int right = _center._x + _halfSize._x;
	int top = _center._y - _halfSize._y;
	int bottom = _center._y + _halfSize._y;

	Ellipse(hdc, left, top, right, bottom);
}

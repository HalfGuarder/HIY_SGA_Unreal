#include "pch.h"
#include "Circle.h"

Circle::Circle(Vector2 center, Vector2 radius)
	: _center(center), _radius(radius)
{
}

void Circle::Update()

{
}

void Circle::Render(HDC hdc)
{
	int left = _center._x - _radius._x;
	int right = _center._x + _radius._x;
	int top = _center._y - _radius._y;
	int bottom = _center._y + _radius._y;

	Ellipse(hdc, left, top, right, bottom);
}

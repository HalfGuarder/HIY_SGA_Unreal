#pragma once
class Circle
{
public:
	// 생성자
	Circle(Vector2 center, Vector2 halfSize);
	~Circle() {};

	void Update();
	void Render(HDC hdc);
	
public:
	// 멤버?
	Vector2 _center;
	Vector2 _halfSize;
};


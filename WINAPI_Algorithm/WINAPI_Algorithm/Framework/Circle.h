#pragma once
class Circle
{
public:
	// ������
	Circle(Vector2 center, Vector2 radius);
	~Circle() {};

	void Update();
	void Render(HDC hdc);
	
public:
	// ���?
	Vector2 _center;
	Vector2 _radius;
};


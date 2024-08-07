#pragma once

#define GREEN_COLOR 0
#define RED_COLOR 1

class CircleCollider
{
public:
	// 생성자
	CircleCollider(Vector2 center, float radius);
	~CircleCollider();

	void Update();
	void Render(HDC hdc);

	bool IsCollision(Vector2 point);
	bool IsCollision(shared_ptr<CircleCollider> other);
	bool IsCollision(shared_ptr<RectCollider> other);

	void SetGreen() { SetColor(GREEN_COLOR); }
	void SetRed() { SetColor(RED_COLOR); }
	
public:
	void SetColor(ColorNum index);

	vector<HPEN> _pens;
	HPEN _curPen;

	Vector2 _center;
	float _radius; // 타원은 게임에서 구현하지 않음
};


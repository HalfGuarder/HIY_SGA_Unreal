#pragma once

#define BLACK_COLOR			0
#define GREEN_COLOR			1
#define RED_COLOR			2
#define SKYCOLOR_COLOR		3

class RectCollider;
class CircleCollider;

using ColorNum = int;

enum class ColliderType
{
	NONE,
	CIRCLE,
	RECT
};

class Collider
{
public:
	Collider(Vector2 center);
	virtual ~Collider();

	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

	bool IsCollision(shared_ptr<Collider> col);

	virtual bool IsCollision(Vector2 point) abstract;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) abstract;
	virtual bool IsCollision(shared_ptr<RectCollider> other) abstract;

	virtual void SetBlack() { SetColor(BLACK_COLOR); }
	virtual void SetGreen() { SetColor(GREEN_COLOR); }
	virtual void SetRed() { SetColor(RED_COLOR); }
	virtual void SetSkyColor() { SetColor(SKYCOLOR_COLOR); }

	Vector2 _center;

protected:
	void SetColor(ColorNum num);

	ColliderType _type = ColliderType::NONE;
	vector<HPEN> _pens;
	HPEN _curPen;
};


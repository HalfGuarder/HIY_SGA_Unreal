#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void OnStart(Vector2 startPos, Vector2 direction);

	void Bounce(shared_ptr<class Map>& map,
				shared_ptr<class Bar> bar,
				vector<vector<shared_ptr<class A_Block>>> block,
				vector<shared_ptr<class A_Block>> fence);

private:
	shared_ptr<Collider> _col;
	Vector2 _direction = Vector2(1, 0);
	float _speed = 1.5f;


};


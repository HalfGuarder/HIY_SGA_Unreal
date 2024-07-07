#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void OnStart();

	void Bounce(shared_ptr<class Map>& map,
				shared_ptr<class Bar> bar,
				vector<vector<shared_ptr<class A_Block>>> block,
				vector<shared_ptr<class A_Block>> fence);

	void SetDir(Vector2 direction) { _direction = direction; }

	wstring CurScore() { return to_wstring(score); }

private:
	shared_ptr<Collider> _col;
	Vector2 _direction = Vector2(1, 0);
	float _speed = 3.5f;
	HBRUSH _brush = CreateSolidBrush(RED);

	int score = 0;

};


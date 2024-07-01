#pragma once
class Cannon
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	void Move();
	void Fire();

	
	bool IsActive();
	bool IsShot(bool isShot);
	bool _isShot = true;

	void TakeDamage();

	shared_ptr<Collider> GetCollider() { return _body; }
	vector<shared_ptr<class Bullet>>& GetBullets() { return _bullets; }

private:
	shared_ptr<Collider> _body;
	shared_ptr<class Barrel> _barrel;
	vector<shared_ptr<class Bullet>> _bullets;

	bool _isMyTurn = false;

	float _angle = 0.0f;

	int _hp;
};


#pragma once
class Bar
{
public:
	Bar();
	~Bar();

	void Move();

	void Update();
	void Render(HDC hdc);

	shared_ptr<Collider> GetCollider() { return _body; }

private:
	shared_ptr<Collider> _body;


};


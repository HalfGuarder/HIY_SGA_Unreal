#include "pch.h"
#include "Cannon.h"
#include "Objects\Barrel.h"
#include "Objects\Bullet.h"

Cannon::Cannon()
{
	_body = make_shared<CircleCollider>(CENTER, 50.0f);
	_barrel = make_shared<Barrel>();
	_hp = 5;
	
	for (int i = 0; i < 30; i++)
	{
		shared_ptr<Bullet> bullet = make_shared<Bullet>();
		bullet->SetActive(false);
		_bullets.push_back(bullet);
	}

	Move();
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	if (!IsActive())
	{
		for (auto bullet : _bullets)
		{
			bullet->SetActive(false);
		}
		return;
	}

	if (!_isShot)
	{
		Move();
		Fire();
	}

	_body->Update();
	_barrel->Update();

	for (auto bullet : _bullets)
	{
		bullet->Update();
	}

	
}

void Cannon::Render(HDC hdc)
{
	if (!IsActive())
	{
		return;
	}

	_barrel->Render(hdc);
	_body->Render(hdc);
	for (auto bullet : _bullets)
	{
		bullet->Render(hdc);
	}
}

void Cannon::Move()
{
	if (GetAsyncKeyState(VK_RIGHT))
	{
		_body->_center._x += 1.0f;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		_body->_center._x -= 1.0f;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		_angle -= 0.01f;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		_angle += 0.01f;
	}

	_barrel->SetAngle(_angle);

	_barrel->SetStart(_body->_center);
}

void Cannon::Fire()
{
	// KEYP DOWN
	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
	{
		/*for (int i = 0; i < _bullets.size(); i++)
		{
			if (_bullets[i]->IsActive() == false)
			{
				_bullets[i]->Fire(_barrel->GetEndPoS(), _barrel->GetDirection());

				return;
			}

			
		}*/
		
		auto iter = std::find_if(_bullets.begin(), _bullets.end(),
		[](shared_ptr<Bullet> bullet)-> bool
		{
			if (!bullet->IsActive())
			{
				return true;
			}

			return false;
		});

		if (iter != _bullets.end())
		{
			(*iter)->Fire(_barrel->GetEndPoS(), _barrel->GetDirection());
			
			IsShot(true);
			// 상속하면 바뀌는가?
		}
	}
}



bool Cannon::IsActive()
{
	if (_hp <= 0)
	{
		return false;
	}

	return true;
}

bool Cannon::IsShot(bool isShot)
{
	_isShot = isShot;

	return _isShot;
}

void Cannon::TakeDamage()
{
	if (_hp < 0)
	{
		_hp = 0;

		return;
	}

	_hp--;

	return;
}

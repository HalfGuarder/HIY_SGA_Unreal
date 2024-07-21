#include "pch.h"
#include "Ball.h"
#include "Map.h"
#include "Bar.h"
#include "A_Block.h"

Ball::Ball()
{
	_col = make_shared<CircleCollider>(Vector2(CENTER), 3);
}

Ball::~Ball()
{
}

void Ball::Update()
{
	_col->Update();
	_col->_center += _direction * _speed;
}

void Ball::Render(HDC hdc)
{
	_col->SetRed();
	SelectObject(hdc, _brush);
	_col->Render(hdc);
}

void Ball::OnStart()
{
	_col->_center = Vector2(1000, 700);
	_direction = Vector2(0, 1);
}

void Ball::Bounce(shared_ptr<class Map>& map,
				shared_ptr<class Bar> bar,
				vector<vector<shared_ptr<A_Block>>> block, 
				vector<shared_ptr<A_Block>> fence)
{
	auto col = dynamic_pointer_cast<CircleCollider>(_col);
	auto barBody = bar->GetCollider();
	int ySize = block.size(); // MAXCOUNT_Y 였음
	int xSize = block[0].size(); // MAXCOUNT_x 였음

	if (col->_center._y > 1400)
	{
		score -= 500;
		if (score < 0)
		{
			score = 0;
		}
		OnStart();
	}

	if (barBody->IsCollision(col))
	{
		Vector2 dir = col->_center - barBody->_center;
		dir.Normalize();
		SetDir(dir);
	}

	for (int i = 0; i < ySize; i++)
	{
		for (int j = 0; j < xSize; j++)
		{
			if (block[i][j]->IsCollision(col))
			{
				if (map->DeletedCheck(block[i][j]))
				{
					continue;
				}

				if (col->_center._y > block[i][j]->_center._y)
				{
					_direction._y *= -1.0f;
					map->DeleteBlock(block[i][j]);
					score += 100;
				}

				else if (col->_center._y < block[i][j]->_center._y)
				{
					_direction._y *= -1.0f;
					map->DeleteBlock(block[i][j]);
					score += 100;
				}
			}
		}
	}


	if (fence[0]->IsCollision(col))
	{
		if (col->_center._x - col->_radius < fence[0]->_center._x + fence[0]->_halfSize._x)
		{
			_direction._x *= -1.0f;
		}
	}
	if (fence[1]->IsCollision(col))
	{
		if (col->_center._x + col->_radius > fence[1]->_center._x - fence[1]->_halfSize._x)
		{
			_direction._x *= -1.0f;
		}
	}
	if (fence[2]->IsCollision(col))
	{
		if (col->_center._y - col->_radius > fence[2]->_center._y + fence[2]->_halfSize._y)
		{
			_direction._y *= -1.0f;
		}
	}

}

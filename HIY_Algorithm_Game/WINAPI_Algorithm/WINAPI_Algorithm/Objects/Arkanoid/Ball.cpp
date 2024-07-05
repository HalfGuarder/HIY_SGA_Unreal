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
	_col->Render(hdc);
}

void Ball::OnStart(Vector2 startPos, Vector2 direction)
{
	_col->_center = startPos;
	_direction = direction;
	_direction.Normalize();
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

	if (barBody->IsCollision(col))
	{
		if (col->_center._x < barBody->_center._x - 50)
		{
				_direction._y *= -1.0f;
				_direction._x *= -1.0f;
		}

		if (col->_center._x > barBody->_center._x + 50)
		{
				_direction._y *= -1.0f;
				_direction._x *= -1.0f;
		}

		if (col->_center._y > barBody->_center._y - 20)
		{
			if (col->_center._x < barBody->_center._x)
			{
				_direction._y *= -1.0f;
				_direction._x = -col->_center.Angle(); // 각도를 어떻게 할 것인가?
			}
			else
			{
				_direction._y *= -1.0f;
				_direction._x = col->_center.Angle();
			}
		}
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
					// 제거 함수
					map->DeleteBlock(block[i][j]);
				}

				else if (col->_center._y < block[i][j]->_center._y)
				{
					_direction._y *= 1.0f;
				}
			}
		}
	}


	if (fence[0]->IsCollision(col))
	{
		if (col->_center._x < fence[0]->_center._x + fence[0]->_halfSize._x)
		{
			_direction._x *= -1.0f;
		}
	}
	if (fence[1]->IsCollision(col))
	{
		if (col->_center._x > fence[0]->_center._x - fence[0]->_halfSize._x)
		{
			_direction._x *= -1.0f;
		}
	}

}

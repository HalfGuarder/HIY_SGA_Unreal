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

void Ball::Bounce(shared_ptr<class Bar> bar,
				vector<vector<shared_ptr<A_Block>>> block, 
				vector<shared_ptr<A_Block>> fence)
{
	auto col = dynamic_pointer_cast<CircleCollider>(_col);
	auto barBody = bar->GetCollider();
	int ySize = block.size(); // MAXCOUNT_Y ����
	int xSize = block[0].size(); // MAXCOUNT_x ����

	if (barBody->IsCollision(col))
	{
		if (col->_center._y > barBody->_center._y)
		{
			if (col->_center._x < barBody->_center._x)
			{
				_direction._y *= -1.0f;
				_direction._x = -col->_center.Angle(); // ������ ��� �� ���ΰ�?
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
				if (col->_center._y > block[i][j]->_center._y)
				{
					_direction._y *= -1.0f;
					// ���� �Լ�
				}

				else if (col->_center._y < block[i][j]->_center._y)
				{
					_direction._y *= 1.0f;
				}
			}
		}
	}
}

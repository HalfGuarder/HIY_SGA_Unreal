#include "pch.h"
#include "Map.h"
#include "A_Block.h"

Map::Map()
{
	Vector2 offSet = Vector2(600, 50);

	// 奇胶 青纺 积己
	SetFence(offSet);

	// 喉废 青纺 积己
	_aBlocks.reserve(MAXCOUNT_Y);

	for (int i = 0; i < MAXCOUNT_Y; i++)
	{
		vector<shared_ptr<A_Block>> aBlocks_x;
		aBlocks_x.reserve(MAXCOUNT_X);

		for (int j = 0; j < MAXCOUNT_X; j++)
		{
			Vector2 aBlockOffSet = offSet + Vector2(25.0f * j, 15.0f * i);

			shared_ptr<A_Block> aBlock = make_shared<A_Block>();
			aBlock->SetBlockType(A_Block::A_BlockType::NONE);
			aBlock->SetPositon(aBlockOffSet);
			aBlocks_x.push_back(aBlock);
		}
		_aBlocks.push_back(aBlocks_x);
	}

	CreateMap();
}

Map::~Map()
{
}

void Map::Update()
{
	for (auto fence : _fences)
	{
		fence->Update();
	}

	for (auto aBlock_x : _aBlocks)
	{
		for (auto aBlock : aBlock_x)
		{
			aBlock->Update();
		}
	}
}

void Map::Render(HDC hdc)
{
	for (auto fence : _fences)
	{
		fence->Render(hdc);
	}

	for (auto aBlock_x : _aBlocks)
	{
		for (auto aBlock : aBlock_x)
		{
			aBlock->Render(hdc);
		}
	}
}

void Map::SetFence(Vector2 offSet)
{
	_fences.reserve(3);

	shared_ptr<A_Block> leftFence = make_shared<A_Block>();
	shared_ptr<A_Block> rightFence = make_shared<A_Block>();
	shared_ptr<A_Block> upperFence = make_shared<A_Block>();

	leftFence->SetBlockType(A_Block::A_BlockType::NONE);
	rightFence->SetBlockType(A_Block::A_BlockType::NONE);
	upperFence->SetBlockType(A_Block::A_BlockType::NONE);

	leftFence->SetPositon(offSet + Vector2(-25.0f, 400.0f));
	rightFence->SetPositon(offSet + Vector2(750.0f, 400.0f));
	upperFence->SetPositon(offSet + Vector2(360.0f, 0.0f));

	leftFence->_halfSize = Vector2(50, 500);
	rightFence->_halfSize = Vector2(50, 500);
	upperFence->_halfSize = Vector2(380, 50);

	_fences.push_back(leftFence);
	_fences.push_back(rightFence);
	_fences.push_back(upperFence);
}

void Map::CreateMap()
{
	for (int y = 0; y < MAXCOUNT_Y; y++)
	{
		for (int x = 0; x < MAXCOUNT_X; x++)
		{
			if (y == 0)
			{
				_aBlocks[y][x]->SetBlockType(A_Block::A_BlockType::NONDESTROY);
				continue;
			}

			if (x == 0)
			{
				_aBlocks[y][x]->SetBlockType(A_Block::A_BlockType::NONDESTROY);
				continue;
			}

			if (x == 29)
			{
				_aBlocks[y][x]->SetBlockType(A_Block::A_BlockType::NONDESTROY);
				continue;
			}

			else
			{
				_aBlocks[y][x]->SetBlockType(A_Block::A_BlockType::NONE);
			}
		}
	}
}

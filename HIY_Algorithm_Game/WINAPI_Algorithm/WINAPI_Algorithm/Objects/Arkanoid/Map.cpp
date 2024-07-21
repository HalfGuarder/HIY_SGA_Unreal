#include "pch.h"
#include "Map.h"
#include "A_Block.h"

Map::Map()
{
	Vector2 offSet = Vector2(700, 100);

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


	_deleteBlocks.reserve(MAXCOUNT_Y * MAXCOUNT_X);
}

Map::~Map()
{
}

void Map::Update()
{
	for (auto aBlock_x : _aBlocks)
	{
		for (auto aBlock : aBlock_x)
		{
			aBlock->Update();
		}
	}

	for (auto deletedBlock : _deleteBlocks)
	{
		deletedBlock->SetBlack();
	}
	
}

void Map::Render(HDC hdc)
{
	int check = 0;

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

	leftFence->SetBlockType(A_Block::A_BlockType::NONEDESTROY);
	rightFence->SetBlockType(A_Block::A_BlockType::NONEDESTROY);
	upperFence->SetBlockType(A_Block::A_BlockType::NONEDESTROY);

	leftFence->SetPositon(offSet + Vector2(-65.0f, 400.0f));
	rightFence->SetPositon(offSet + Vector2(665.0f, 400.0f));
	upperFence->SetPositon(offSet + Vector2(280.0f, -60.0f));

	leftFence->_halfSize = Vector2(50, 500);
	rightFence->_halfSize = Vector2(50, 500);
	upperFence->_halfSize = Vector2(380, 50);

	_fences.push_back(leftFence);
	_fences.push_back(rightFence);
	_fences.push_back(upperFence);

	for (auto fence : _fences)
	{
		fence->Update();
	}
}

vector<vector<shared_ptr<A_Block>>> Map::GetBlocks()
{
	return _aBlocks;
}

vector<shared_ptr<A_Block>> Map::GetFences()
{
	return _fences;
}

shared_ptr<A_Block> Map::GetSingleBlock(int Y, int X)
{
	return _aBlocks[Y][X];
}

void Map::CreateMap()
{
	for (int y = 0; y < MAXCOUNT_Y; y++)
	{
		for (int x = 0; x < MAXCOUNT_X; x++)
		{
			_aBlocks[y][x]->SetBlockType(A_Block::A_BlockType::DESTROY);
		}
	}
}

void Map::DeleteBlock(shared_ptr<A_Block> block)
{
	block->SetBlockType(A_Block::A_BlockType::NONE);
	
	_deleteBlocks.push_back(block);
}

bool Map::DeletedCheck(shared_ptr<A_Block> block)
{
	auto iter = std::find(_deleteBlocks.begin(), _deleteBlocks.end(), block);

	if (iter != _deleteBlocks.end())
	{
		return true;
	}

	return false;
}

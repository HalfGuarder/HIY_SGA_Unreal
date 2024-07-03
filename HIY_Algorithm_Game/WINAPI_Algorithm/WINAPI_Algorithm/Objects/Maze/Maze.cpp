#include "pch.h"
#include "Maze.h"
#include "Block.h"

Maze::Maze()
{
	Vector2 offSet = Vector2(450, 150);

	_blocks.reserve(MAXCOUNT_Y);

	for (int i = 0; i < MAXCOUNT_Y; i++)
	{
		vector<shared_ptr<Block>> blocks_x;
		blocks_x.reserve(MAXCOUNT_X);

		for (int j = 0; j < MAXCOUNT_X; j++)
		{
			Vector2 blockOffSet = offSet + Vector2(16.0f * j, 16.0f * i);

			shared_ptr<Block> block = make_shared<Block>();
			block->SetBlockType(Block::BlockType::DISABLE);
			block->SetPosition(blockOffSet);
			blocks_x.push_back(block);
		}
		_blocks.push_back(blocks_x);
	}

	CreateMaze();
}

Maze::~Maze()
{
}

void Maze::Update()
{
	for (auto block_x : _blocks)
	{
		for (auto block : block_x)
		{
			block->Update();
		}
	}
}

void Maze::Render(HDC hdc)
{
	for (auto block_x : _blocks)
	{
		for (auto block : block_x)
		{
			block->Render(hdc);
		}
	}
}

void Maze::CreateMaze()
{
	// 프로그래머를 위한 미로 만들기

	// 갈 수 있는 노드들을 만들기
	for (int y = 0; y < MAXCOUNT_Y; y++)
	{
		for(int x = 0; x < MAXCOUNT_X; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				_blocks[y][x]->SetBlockType(Block::BlockType::DISABLE);
			}
			else
			{
				_blocks[y][x]->SetBlockType(Block::BlockType::ABLE);
			}
		}
	}


	for (int y = 0; y < MAXCOUNT_Y; y++)
	{
		for (int x = 0; x < MAXCOUNT_X; x++)
		{
			if (x == 1 && y == 1) // 시작점
			{
				_blocks[y][x]->SetBlockType(Block::BlockType::ABLE);
			}

			if (x == MAXCOUNT_X - 2 && y == MAXCOUNT_Y - 2) // 끝점
			{
				_blocks[y][x]->SetBlockType(Block::BlockType::ABLE);
				continue;
			}

			if (x % 2 == 0 || y % 2 == 0)
			{
				// _blocks[y][x]->SetBlockType(Block::BlockType::DISABLE);
				continue;
			}
			
			if (x == MAXCOUNT_X - 2)
			{
				_blocks[y + 1][x]->SetBlockType(Block::BlockType::ABLE);
				continue;
			}

			if (y == MAXCOUNT_Y - 2)
			{
				_blocks[y][x + 1]->SetBlockType(Block::BlockType::ABLE);
				continue;
			}

			// 난수를 이용하여 오른쪽 혹은 아래 쪽 선택해서 뚫기
			int randValue = rand() % 2;
			if (randValue == 0)
			{
				_blocks[y][x + 1]->SetBlockType(Block::BlockType::ABLE);
			}
			else
			{
				_blocks[y+1][x]->SetBlockType(Block::BlockType::ABLE);
			}
		}
	}
}

Block::BlockType Maze::GetBlockType(int y, int x)
{
	return _blocks[y][x]->GetBlockType();
}

void Maze::SetPlayerPos(Vector2 pos)
{
	_blocks[pos._y][pos._x]->SetBlockType(Block::BlockType::PLAYER_POS);
}

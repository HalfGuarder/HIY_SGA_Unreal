#pragma once

#include "A_Block.h"

class A_Block;

#define MAXCOUNT_X 30
#define MAXCOUNT_Y 50

class Map
{
public:
	Map();
	~Map();

	void Update();
	void Render(HDC hdc);

	void SetFence(Vector2 offSet);

	void CreateMap();
	


private:
	vector<vector<shared_ptr<A_Block>>> _aBlocks;
	vector<shared_ptr<A_Block>> _fences;
};


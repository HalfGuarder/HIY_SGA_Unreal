#include "pch.h"
#include "Player.h"

#include "Maze.h"
#include "Block.h"

Player::Player(shared_ptr<Maze> maze)
{
	_maze = maze;
}

Player::~Player()
{
	_maze = nullptr;
}

void Player::BeginPlay()
{
	_maze->SetPlayerPos(_pos);
	_pos = _maze->GetStartPos();

	_visited = vector<vector<bool>>(MAXCOUNT_Y, vector<bool>(MAXCOUNT_X, false));

	AStar(_pos, _maze->GetEndPos());
}

void Player::RightHand()
{
	// 실습
	// 우수법을 이용해서 미로의 끝점까지 가면 된다.
	// 찾은 길은 _path에 넣는다.

	enum Direction
	{
		UP,
		LEFT,
		BOTTOM,
		RIGHT,

		DIR_COUNT = 4
	};

	Vector2 pos = _pos;
	_path.push_back(pos);
	Vector2 endPos = _maze->GetEndPos();

	Direction dir = Direction::BOTTOM;

	Vector2 frontPos[4] =
	{
		Vector2 {0, -1}, // UP
		Vector2 {-1, 0}, // LEFT
		Vector2 {0, 1},	// BOTTOM
		Vector2 {1,0}	// RIGHT
	};

	while (true)
	{
		if (pos == endPos)
		{
			break;
		}

		// % - 알고리즘 순환 구조에서 많이 쓰인다.
		int newDir = (dir - 1 + DIR_COUNT) % DIR_COUNT;
		Vector2 oldDirVector2 = frontPos[dir];
		Vector2 newDirVector2 = frontPos[newDir];

		Vector2 newPos = pos + newDirVector2; // 플레이어 오른쪽 방향
		Vector2 oldPos = pos + oldDirVector2; // 플레이어 앞 방향

		// 오른쪽으로 갈 수 있으면 방향을 바꾸고 오른쪽으로 진행
		if (CanGo(newPos._y, newPos._x))
		{
			dir = static_cast<Direction>(newDir);
			pos += newDirVector2;
			_path.push_back(pos);
		}
		// 오른쪽이 막혀 있고, 앞쪽으로 갈 수 있으면 방향 그대로 앞으로 진행
		else if (CanGo(oldPos._y, oldPos._x))
		{
			pos += oldDirVector2;
			_path.push_back(pos);
		}
		// 오른쪽, 앞쪽 둘 다 막혀 있을 때 왼쪽으로 회전
		else
		{
			dir = static_cast<Direction>((dir + 1 + DIR_COUNT) % DIR_COUNT);
		}

		stack<Vector2> s;

		for (int i = 0; i < _path.size() - 1; i++)
		{
			if (s.empty() == false && s.top() == _path[i + 1])
			{
				s.pop();
			}
			else
			{
				s.push(_path[i]);
			}
		}

		s.push(_path.back());

		_path.clear();

		while (true)
		{
			if (s.empty() == true)
			{
				break;
			}
			_path.push_back(s.top());
			s.pop();
		}

		std::reverse(_path.begin(), _path.end());
	}

}

void Player::DFS(Vector2 start)
{
	Vector2 frontPos[8] =
	{
		Vector2 {0, -1},	// UP
		Vector2 {-1, 0},	// LEFT
		Vector2 {0, 1},		// BOTTOM
		Vector2 {1, 0},		// RIGHT

		Vector2 {-1, -1},	// UP LEFT
		Vector2 {-1, 1},	// LEFT BOTTOM
		Vector2 {1, 1},		// BOTTOM RIGIHT
		Vector2 {1, -1}		// RIGHT UP
	};

	// 계속 초기화 되는 문제 -> DFS 함수 밖으로 꺼내야 함.
	//vector<vector<bool>> visited = vector<vector<bool>>(MAXCOUNT_Y, vector<bool>(MAXCOUNT_X, false));

	Vector2 endPos = _maze->GetEndPos();
	Vector2 here = start;

	if (_path.size() == 0)
	{
		_path.push_back(start);
	}

	_visited[here._y][here._x] = true;

	for (int i = 0; i < 8; i++)
	{
		Vector2 there = here + frontPos[i];
		
		if (!CanGo(there._y, there._x)) continue;

		if (_visited[there._y][there._x]) continue;

		if (there == endPos)
		{
			_path.push_back(there);
			_maze->SetBlockType(there._y, there._x, Block::BlockType::FOOT_PRINT);
			break;
		}

		_maze->SetBlockType(there._y, there._x, Block::BlockType::FOOT_PRINT);
		_path.push_back(there);
		DFS(there);
	}
}

void Player::BFS(Vector2 start)
{
	Vector2 frontPos[8] =
	{
		Vector2 {0, -1},	// UP
		Vector2 {-1, 0},	// LEFT
		Vector2 {0, 1},		// BOTTOM
		Vector2 {1, 0},		// RIGHT

		Vector2 {-1, -1},	// UP LEFT
		Vector2 {-1, 1},	// LEFT BOTTOM
		Vector2 {1, 1},		// BOTTOM RIGIHT
		Vector2 {1, -1}		// RIGHT UP
	};

	vector<vector<bool>> discovered = vector<vector<bool>>(MAXCOUNT_Y, vector<bool>(MAXCOUNT_X, false));
	vector<vector<Vector2>> parent = vector<vector<Vector2>>(MAXCOUNT_Y, vector<Vector2>(MAXCOUNT_X, Vector2(-1, -1)));

	Vector2 pos = start; // 없어도 되는가?
	Vector2 endPos = _maze->GetEndPos();

	discovered[start._y][start._x] = true;
	parent[start._y][start._x] = start;

	queue<Vector2> q;
	q.push(start);

	while (true)
	{
		if (q.empty()) break;

		Vector2 here = q.front();
		q.pop();

		// 지금 큐의 front가 도착점이면 break
		if (here == endPos) break;

		for (int i = 0; i < 8; i++)
		{
			Vector2 there = here + frontPos[i];
			
			// there가 갈 수 있는 블록인지 확인
			if (!CanGo(there._y, there._x)) continue;
			// there가 방문 되어 있는지 확인
			if (discovered[there._y][there._x] == true) continue;

			// 탐색했으면 색을 변경
			_maze->SetBlockType(there._y, there._x, Block::BlockType::FOOT_PRINT);

			q.push(there);
			discovered[there._y][there._x] = true;
			parent[there._y][there._x] = here;
		}
	}

	Vector2 check = endPos;
	_path.push_back(check);
	while (true)
	{
		if (check == start) break;

		check = parent[check._y][check._x];
		_path.push_back(check);
	}

	std::reverse(_path.begin(), _path.end());
}

void Player::Dijkstra(Vector2 start)
{
	Vector2 frontPos[8] =
	{
		Vector2 {0, -1},	// UP
		Vector2 {-1, 0},	// LEFT
		Vector2 {0, 1},		// BOTTOM
		Vector2 {1, 0},		// RIGHT

		Vector2 {-1, -1},	// UP LEFT
		Vector2 {-1, 1},	// LEFT BOTTOM
		Vector2 {1, 1},		// BOTTOM RIGIHT
		Vector2 {1, -1}		// RIGHT UP
	};

	vector<vector<Vector2>> parent
		= vector<vector<Vector2>>(MAXCOUNT_Y, vector<Vector2>(MAXCOUNT_X, Vector2(-1, -1)));
	vector<vector<int>> best
		= vector<vector<int>>(MAXCOUNT_Y, vector<int>(MAXCOUNT_X, INT_MAX));
	priority_queue<Vertex_Dijkstra, vector<Vertex_Dijkstra>, greater<Vertex_Dijkstra>> pq;

	Vertex_Dijkstra startV;
	startV.pos = start;
	startV.g = 0;
	pq.push(startV);

	best[start._y][start._x] = 0;
	parent[start._y][start._x] = start;

	while (true)
	{
		if (pq.empty()) break;

		Vertex_Dijkstra hereV = pq.top();
		pq.pop();

		if (hereV.pos == _maze->GetEndPos()) break;

		// 전에 발견한 곳이 더 좋은 경로였을 때
		if (best[hereV.pos._y][hereV.pos._x] < hereV.g) continue;

		// 다음 경로 탐색
		for (int i = 0; i < 8; i++)
		{
			Vector2 there = hereV.pos + frontPos[i];

			if (!CanGo(there._y, there._x)) continue;

			int newCost = 0;
			if (i > 3)
			{
				newCost = hereV.g + 10;
			}
			else
			{
				newCost = hereV.g + 14;
			}

			if (newCost >= best[there._y][there._x]) continue;

			Vertex_Dijkstra thereV;
			thereV.pos = there;
			thereV.g = newCost;

			pq.push(thereV);
			_maze->SetBlockType(thereV.pos._y, thereV.pos._x, Block::BlockType::FOOT_PRINT);
			best[there._y][there._x] = newCost;
			parent[there._y][there._x] = hereV.pos;
		}
	}

	Vector2 check = _maze->GetEndPos();
	_path.push_back(check);
	while (true)
	{
		if (check == start) break;

		check = parent[check._y][check._x];
		_path.push_back(check);
	}

	std::reverse(_path.begin(), _path.end());
}

void Player::AStar(Vector2 start, Vector2 end)
{
	Vector2 frontPos[8] =
	{
		Vector2 {0, -1},	// UP
		Vector2 {-1, 0},	// LEFT
		Vector2 {0, 1},		// BOTTOM
		Vector2 {1, 0},		// RIGHT

		Vector2 {-1, -1},	// UP LEFT
		Vector2 {-1, 1},	// LEFT BOTTOM
		Vector2 {1, 1},		// BOTTOM RIGIHT
		Vector2 {1, -1}		// RIGHT UP
	};

	vector<vector<Vector2>> parent
		= vector<vector<Vector2>>(MAXCOUNT_Y, vector<Vector2>(MAXCOUNT_X, Vector2(-1, -1)));
	vector<vector<int>> best
		= vector<vector<int>>(MAXCOUNT_Y, vector<int>(MAXCOUNT_X, INT_MAX));
	priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;

	Vertex startV;
	startV.pos = start;
	startV.g = 0;
	startV.h = start.ManhattanDistance(_maze->GetEndPos()) * 10.0f;
	startV.f = startV.g + startV.h;
	pq.push(startV);

	best[start._y][start._x] = startV.f;
	parent[start._y][start._x] = start;

	while (true)
	{
		if (pq.empty()) break;

		Vertex hereV = pq.top();
		pq.pop();

		if (hereV.pos == _maze->GetEndPos()) break;

		// 전에 발견한 곳이 더 좋은 경로였을 때
		if (best[hereV.pos._y][hereV.pos._x] < hereV.f) continue;

		// 다음 경로 탐색
		for (int i = 0; i < 8; i++)
		{
			Vector2 there = hereV.pos + frontPos[i];

			if (!CanGo(there._y, there._x)) continue;

			int newCost = 0;
			if (i < 4)
			{
				newCost = hereV.g + 10;
			}
			else
			{
				newCost = hereV.g + 14;
			}

			int h = hereV.pos.ManhattanDistance(_maze->GetEndPos()) * 10.0f;
			int f = newCost + h;

			if (f >= best[there._y][there._x]) continue;

			Vertex thereV;
			thereV.pos = there;
			thereV.g = newCost;
			thereV.h = h;
			thereV.f = f;

			pq.push(thereV);
			_maze->SetBlockType(thereV.pos._y, thereV.pos._x, Block::BlockType::FOOT_PRINT);
			best[there._y][there._x] = f;
			parent[there._y][there._x] = hereV.pos;
		}
	}

	Vector2 check = _maze->GetEndPos();
	_path.push_back(check);
	while (true)
	{
		if (check == start) break;

		check = parent[check._y][check._x];
		_path.push_back(check);
	}

	std::reverse(_path.begin(), _path.end());
}

bool Player::CanGo(int y, int x) // y , x 값 얻기
{
	Block::BlockType blockType = _maze->GetBlockType(y, x);
	if (blockType == Block::BlockType::ABLE)
	{
		return true;
	}

	return false;
}

void Player::Update()
{
	if (_pathIndex >= _path.size())
	{
		_pathIndex = 0;
		_path.clear();
		
		return;
	}

	_time += 0.3f;
	if (_time > 1.0f)
	{
		_time = 0.0f;
		_pos = _path[_pathIndex];

		if (_pathIndex != 0)
		{
			// 발자취
			_maze->SetPlayerPos(_pos);
		}

		_pathIndex++;
	}
}
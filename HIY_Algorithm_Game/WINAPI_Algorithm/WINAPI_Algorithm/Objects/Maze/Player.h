#pragma once

class Maze;
class Block;

class Player
{
public:
	struct Vertex_Dijkstra
	{
		bool operator<(const Vertex_Dijkstra& other) const
		{
			if (g < other.g) return true;

			return false;
		}

		bool operator>(const Vertex_Dijkstra& other) const
		{
			if (g > other.g) return true;

			return false;
		}

		float g;
		Vector2 pos;
	};

	struct Vertex
	{
		bool operator<(const Vertex& other) const
		{
			if (f < other.f) return true;

			return false;
		}

		bool operator>(const Vertex& other) const
		{
			if (f > other.f) return true;

			return false;
		}

		float g;
		float h; // 휴리스틱 함수 -> 맨하튼 거리 함수
		float f; // g + h
		Vector2 pos;
	};

	Player(shared_ptr<Maze> maze);
	~Player();

	void BeginPlay();

	void RightHand();
	void DFS(Vector2 start);
	void BFS(Vector2 start);
	void Dijkstra(Vector2 start);
	void AStar(Vector2 start, Vector2 end);

	bool CanGo(int y, int x);

	void Update();

private:
	Vector2 _pos = { 1,1 };

	vector<Vector2> _path;
	int _pathIndex = 0;
	float _time = 0.0f;

	Vector2 _dir = Vector2(0, 1);

	shared_ptr<Maze> _maze;

	// DFS
	vector<vector<bool>> _visited;

	// Dijkstra
};


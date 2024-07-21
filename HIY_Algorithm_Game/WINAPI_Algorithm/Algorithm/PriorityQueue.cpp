#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <concurrent_priority_queue.h>

using namespace std;

// 우선 순위 큐
// 1. 완전 이진 트리
// 2. 부모가 항상 자식보다 크다(최대 힙)

class Priority_queue
{
public:
	void push(const int& value)
	{
		_container.push_back(value);

		int now = _container.size() - 1;
		

		while (true)
		{
			if (now == 0)
			{
				return;
			}

			int parent = (now - 1) / 2;

			if (_container[now] < _container[parent])
				break;

			std::swap(_container[now], _container[parent]);
			now = parent;
		}

	}

	void pop()
	{
		_container[0] = _container.back();
		_container.pop_back();

		int now = 0;

		while (true)
		{
			int leftChild = now * 2 + 1;
			int rightChild = now * 2 + 2;

			if (leftChild >= (int)_container.size())
			{
				break;
			}

			int next = now;
			if (_container[next] < _container[leftChild])
			{
				next = leftChild;
			}

			if (rightChild < (int)_container.size() && _container[next] < _container[rightChild])
			{
				next = rightChild;
			}

			if (next == now) break;

			std::swap(_container[now], _container[next]);
			now = next;
		}
	}

	const int& top()
	{
		return _container.front();
	}

	bool empty()
	{
		if (_container.size() == 0)
		{
			return true;
		}
		return false;
	}

private:
	vector<int> _container;
};

int main()
{
	//priority_queue<int> pq;
	Priority_queue pq;

	pq.push(5);
	pq.push(2);
	pq.push(11);
	pq.push(80);
	pq.push(90);
	pq.push(0);
	pq.push(99);

	// N개에서 M만큼만 정렬하고 싶다.
	// => partial_sort => M * logN
	while (true)
	{
		if (pq.empty()) break;

		int top = pq.top();
		cout << top << endl;

		pq.pop();
	}

	return 0;
}
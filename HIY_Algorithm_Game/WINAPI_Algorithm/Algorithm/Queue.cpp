#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

// queue : 줄 세우기(게임에서 큐 돌린다)
// First Input First Out : FIFO

template <typename T, typename Container = list<int>>
class Queue
{
public:
	void push(const T& value)
	{
		_queue.push_back(value);
	}

	bool empty()
	{
		return _queue.size() == 0;
	}

	const T& front()
	{
		return _queue.front();
	}

	void pop()
	{
		_queue.pop_front();
	}

private:
	Container _queue;

};

int main()
{
	Queue<int, list<int>> q;

	q.push(51);
	q.push(2);
	q.push(3);
	q.push(23);
	q.push(77);

	while (true)
	{
		if (q.empty() == true)
		{
			break;
		}

		cout << q.front() << endl; // 업무
		q.pop();
	}

	return 0;
}
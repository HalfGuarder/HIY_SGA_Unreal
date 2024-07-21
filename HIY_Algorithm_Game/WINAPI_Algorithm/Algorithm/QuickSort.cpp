#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>


using namespace std;

// Heap Sort
// 힙 트리에 하나 씩 다 집어 넣고 하나 씩 꺼낸다

// 평균 시간 복잡도 : N * logN
// 최악의 경우 : N^2

int Partition(vector<int>& v, int left, int right)
{
	int pivot = v[left];
	int lowIndex = left + 1;
	int highIndex = right;

	while (true)
	{
		if (lowIndex > highIndex) break;

		// lowIndex는 항상 pivot보다 작아야 한다.
		// 작으면 다음 index를 확인한다.
		while (lowIndex <= right - 1 && pivot >= v[lowIndex])
		{
			lowIndex++;
		}
		
		// highIndex는 항상 pivot보다 커야 한다.
		// 크면 이전 index를 확인한다.
		while (highIndex >= left + 1 && pivot <= v[highIndex])
		{
			highIndex--;
		}

		if (lowIndex < highIndex)
		{
			std::swap(v[lowIndex], v[highIndex]);
		}
	}

	std::swap(v[highIndex], v[left]);

	return highIndex;
}

void QuickSort(vector<int>& v, int left, int right)
{
	// 기저 사항
	if (left > right) return;
	
	int pivotIndex = Partition(v, left, right);
	cout << left << " ~ " << pivotIndex - 1 << endl;

	QuickSort(v, left, pivotIndex - 1);
	QuickSort(v, pivotIndex + 1, right);
	
}

int main()
{
	vector<int> v = { 55,30,15,100,1,5,70,30 };
	//QuickSort(v, 0, v.size() - 1);
	std::sort(v.begin(), v.end());
	


	return 0;
}
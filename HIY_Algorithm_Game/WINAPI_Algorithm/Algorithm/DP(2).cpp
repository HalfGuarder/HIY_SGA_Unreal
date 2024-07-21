#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// LIS (Longest Increasing Subsequence)
// 최장 증가 부분 수열

vector<int> v = { 5, 6, 7, 1, 2, 3, 4 };
// 증가 부분 수열 : 점점 증가 되는 부분 수열
// 최장 증가 부분 수열 : 증가 부분 수열 중에서 가장 긴 것

// LIS(4) : 1
// LIS(3) ... v[3] <= v[next] -> 2
// LIS(2) ... v[2] <= v[3] -> 3 / v[2] <= v[4] -> 2
// LIS(1) ... LIS(2) + 1 / LIS(3) + 1 ...

vector<int> cache;

int LIS(int pos)
{
	// 기저 사항
	if (pos == v.size() - 1) return 1;

	// 메모이제이션
	int& ref = cache[pos];
	if (ref != -1) return ref;

	ref = 1;
	for (int next = pos + 1; next < v.size(); next++)
	{
		if (v[pos] <= v[next])
		{
			ref = max(ref, LIS(next) + 1);
		}
	}

	return ref;
}

int main()
{
	cache = vector<int>(v.size(), -1);
	int lis = 1;

	for (int i = 0; i < v.size(); i++)
	{
		lis = max(lis, LIS(i));
	}

	cout << lis << endl;

	return 0;
}
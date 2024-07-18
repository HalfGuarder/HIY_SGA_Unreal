#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int M = 0;
int N = 0;
vector<int> v;
vector<vector<int>> sub;



void Input()
{
	cin >> N;
	cin >> M;

	v.reserve(N);
	sub.reserve(M);

	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
	}

	for (int j = 0; j < M; j++)
	{
		vector<int> tempV;

		int a = 0;
		int b = 0;
		cin >> a;
		cin >> b;

		tempV.push_back(a);
		tempV.push_back(b);

		sub.push_back(tempV);
	}
}

vector<int> sumArr;
void CreateSumArr()
{
	sumArr.reserve(N);

	sumArr.push_back(v[0]);
	for (int i = 0; i < N - 1; i++)
	{
		int temp = sumArr[i] + v[i + 1];
		sumArr.push_back(temp);
	}
}

int main()
{
	Input();
	CreateSumArr();

	for (int i = 0; i < M; i++)
	{
		int a = sub[i][0];
		int b = sub[i][1];

		if (a == 1)
		{
			printf("%d\n", sumArr[b - 1]);
		}
		else
		{
			printf("%d\n", sumArr[b - 1] - sumArr[a - 2]);
		}
	}


	return 0;
}
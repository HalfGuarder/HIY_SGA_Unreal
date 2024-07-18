#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// Enchant
// N만큼 강화
// +1, +2, +3

int N = 0; // 100000
// +1 +1 +1
// +1 +2
// +2 +1
// +3
// ... result = 4

vector<int> enchantV = { 1, 2, 3 };

vector<int> cache = vector<int>(100001, -1);

int Enchant1(int num) // 0 강화일 때 1이 나옴
{
	// 기저 사항
	if (num == N) return 1;
	if (num > N) return 0;

	int& ref = cache[num];
	if (ref != -1) return ref;

	return ref = Enchant1(num + 1) + Enchant1(num + 2) + Enchant1(num + 3);
}


int Enchant3(int num) // 0 강화일 때 1이 나옴
{
	// 기저 사항
	if (num == 0) return 1;
	if (num < 0) return 0;

	int& ref = cache[num];
	if (ref != -1) return ref;

	return ref = Enchant1(num - 1) + Enchant1(num - 2) + Enchant1(num - 3);
}


int Enchant2(int target)
{
	// 기저 사항
	if (target == 0) return 0;
	if (target == 1) return 1;
	if (target == 2) return 2;
	if (target == 3) return 4;

	// 메모이제이션
	int& ref = cache[target];

	if (ref != -1) return ref;

	// 구하기
	ref = Enchant2(target - 1) + Enchant2(target - 2) + Enchant2(target - 3);

	return ref;
}


int main()
{
	int result = Enchant2(0);
	
	// 서식 지정자
	// %c : character
	// %s : string
	// %d : 부호 있는 10진 정수 decimal
	// %f : float
	int tmp = 1;
	printf("Hello World! %d \n .... tmp : %d", result, tmp);

	return 0;
}
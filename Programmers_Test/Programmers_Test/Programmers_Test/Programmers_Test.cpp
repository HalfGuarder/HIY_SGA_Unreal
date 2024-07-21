#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void SortNum(vector<int> numlist, int here, int n)
{
    if (here == 0) return;

    int i = 1;
    
    while (true)
    {
        int there = here - i;

        int h = abs(n - numlist[here]);
        int t = abs(n - numlist[there]);

        if (h < t)
        {
            swap(numlist[there], numlist[here]);
            SortNum(numlist, here, n);
        }
        else if (h == t)
        {
            if (numlist[here] - numlist[there] > 0)
            {
                swap(numlist[there], numlist[here]);
                SortNum(numlist, here, n);
            }
        }

        i++;
        if (i > here) break;
    }
}

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;

    for (int i = numlist.size() - 1; i >= 0; i--)
    {
        SortNum(numlist, i, n);
    }

    return answer = numlist;
}

int main()
{
    vector<int> numlist = { 10000, 20, 36, 47, 40, 6, 10, 7000 };
    int n = 30;
    solution(numlist, 30);

	return 0;
}
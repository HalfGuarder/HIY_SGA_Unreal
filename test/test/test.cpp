#include <string>
#include <vector>

using namespace std;



void DFS(int n, vector<vector<int>> computers, vector<bool>& visitied, int here)
{
    visitied[here] = true;

    for (int there = 0; there < n; there++)
    {
        if (computers[here][there] == 0)
        {
            continue;
        }
        if (visitied[there] == true)
        {
            continue;
        }

        DFS(n, computers, visitied, there);
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visitied = vector<bool>(n, false);

    for (int i = 0; i < n; i++)
    {
        if (visitied[i] == true)
        {
            continue;
        }
        answer++;
        DFS(n, computers, visitied, i);
    }

    return answer;
}

void main()
{
    
}
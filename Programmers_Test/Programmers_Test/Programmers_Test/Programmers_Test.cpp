#include <string>
#include <vector>

using namespace std;

vector<vector<int>> students = {};
vector<int> student = {};

vector<int> s1 = { 1, 2, 3, 4, 5 };
vector<int> s2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
vector<int> s3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

vector<int> a;

vector<int> correct = {};
int cCount = 0;

void DFS(int s)
{
    cCount = 0;
    int num = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (students[s][num] == a[i]) cCount++;

        if (num == students[s].size() - 1) num = 0;

        num++;
    }

    if (correct.size() == 0)
    {
        correct.push_back(cCount);
        student.push_back(s + 1);

        return;
    }

    if (correct[0] < cCount)
    {
        correct[0] = cCount;
        student.clear();
        student.push_back(s + 1);

    }
    else if (correct[0] == cCount)
    {
        student.push_back(s + 1);
    }
}

void DFS_ALL()
{
    for (int s = 0; s < 3; s++)
    {
        DFS(s);
    }
}


vector<int> solution(vector<int> answers) {
    a = answers;


    students.push_back(s1);
    students.push_back(s2);
    students.push_back(s3);

    DFS_ALL();



    return student;
}
int main()
{
    vector<int> answers = { 1, 3, 3, 1, 1 };

    solution(answers);

    return 0;
}


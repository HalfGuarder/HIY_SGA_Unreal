#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

// stack : 팬케이크
// FILO : First Input Last Out

// int
template<typename T, typename Container = vector<int>>
class Stack
{
public:
    void Push(const T& value) { _stack.push_back(value); }

    void Pop() { _stack.pop_back(); }

    bool Empty() { return _stack.size() == 0; }

    const T& Top() { return _stack.back(); }

private:
    Container _stack;
};


int main()
{
    Stack<int> s;

    s.Push(1);
    s.Push(3);
    s.Push(5);
    s.Push(7);
    s.Push(9);

    while (true)
    {
        if (s.Empty())
        {
            break;
        }
        cout << s.Top() << endl;
        s.Pop();
    }


    return 0;
}

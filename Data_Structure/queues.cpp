#include <iostream>

using namespace std;

const int N = 100010;

int q[N], head, tail = -1;

signed main()
{
    int m;
    cin >> m;
    while (m--)
    {
        string op;
        int x;
        cin >> op;
        if (op == "push")
        {
            cin >> x;
            q[++tail] = x;
        } // 入队
        else if (op == "pop")
            head++; // 出队
        else if (op == "empty")
            cout << (head <= tail ? "NO" : "YES") << endl; // 判空
        else
            cout << q[head] << endl; // 取队首元素
    }
    return 0;
}
#include <iostream>

using namespace std;

const int N = 100010;

int stk[N], top; // 从1开始

signed main()
{
    ios::sync_with_stdio(0);

    int m;
    cin >> m;

    while (m--)
    {
        string op;
        cin >> op;
        int x;
        if (op == "push")
        {
            cin >> x;
            stk[++top] = x;
        }
        else if (op == "pop")
        {
            if (top > 0)
                top--;
        }
        else if (op == "empty")
            cout << (top ? "NO" : "YES") << "\n";
        else
            cout << stk[top] << "\n";
    }
    return 0;
}
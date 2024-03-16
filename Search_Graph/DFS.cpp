#include <iostream>

using namespace std;

const int N = 10;

int n;         //
int path[N];   // 记录已经遍历的数字
bool state[N]; // 记录访问状态

// path [n1,n2,n3,n4,n5,0 ,0,0,0,0] n:1-5
// state[0 ,b1,b2,b3,b4,b5,0,0,0,0] b:0-1
void DFS_search(int u)
{
    if (u == n)
    { // 一次遍历结束,输出节点信息
        for (int i = 0; i < n; i++)
        {
            cout << path[i] << " ";
        }
        cout << "\n";
        return;
    }
    // 递归部分
    for (int i = 1; i <= n; i++)
    {
        if (!state[i])
        {
            path[u] = i;
            state[i] = true;
            DFS_search(u + 1);
            state[i] = false;
        }
    }
}
signed main()
{
    cin >> n;

    DFS_search(0);

    return 0;
}

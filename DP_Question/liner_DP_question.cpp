#include <iostream>
#include <algorithm>
using namespace std;

const int N = 500 + 10;

int n;

int dp[N][N];

signed main()
{
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
            cin >> dp[i][j];
    }

    // 从倒数第二层开始DP，初始状态为倒数第一层
    for (int i = n - 1; i; --i)
    {
        for (int j = 0; j <= i; ++j)
            dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]) // 贪心思想，每次取较大的值
    }

    cout << dp[1][1];
}
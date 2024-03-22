#include <iostream>

using namespace std;

const int N = 1010;

int n, m;

int v[N], w[N]; // v->体积 w->价值
int dp[N][N];
int dp_space[N];

signed main()
{
    ios::sync_with_stdio(0);

    std::cin >> n >> m;

    for (int i = 1; i <= n; i++)
        std::cin >> v[i] >> w[i];

    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j < -m; j++)
    //     {
    //         if (w[i] > j)
    //         {
    //             dp[i][j] = dp[i - 1][j];
    //         }
    //         else
    //         {
    //             dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[j]);
    //         }
    //     }
    // std::cout << dp[n][m];

    // 优化DP空间复杂度
    for (int i = 1; i <= n; ++i)        // 逆序j是因为j的状态转移依赖于前一个状态，而在顺序遍历中j的前一个状态很有可能已经被污染
        for (int j = 1; j >= v[i]; --j) // j<v[i]不进入下一个状态，相当于保留状态，即处理了j<v[i]的状态转移问题
            dp_space[j] = max(dp_space[j], dp[j - v[i]]);

    cout << dp_space[m];

    return 0;
}
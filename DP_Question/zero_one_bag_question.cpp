#include <iostream>

using namespace std;

const int N = 1010;

int n, m;

int v[N], w[N]; // v->体积 w->价值
int dp[N][N];

signed main()
{
    ios::sync_with_stdio(0);

    std::cin >> n >> m;

    for (int i = 1; i <= n; i++)
        std::cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j < -m; j++)
        {
            if (w[i] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[j]);
            }
        }

    std::cout << dp[n][m];
}
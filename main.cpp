#include <bits/stdc++.h>

int maxProfit(std::vector<int> &prices)
{
    int pre = 0, cur = 1;
    int ans = 0;
    while (cur < prices.size())
    {
        if (prices[pre] >= prices[cur])
        {
            pre = cur;
            cur++;
            continue;
        }
        else if (prices[pre] < prices[cur])
        {
            ans = std::max(ans, prices[cur] - prices[pre]);
            cur++;
        }
        return ans;
    }
}
signed main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
        std::cin >> arr[i];
    std::cout << maxProfit(arr) << std::endl;
}
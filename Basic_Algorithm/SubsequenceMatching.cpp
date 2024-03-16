#include <iostream>
#include <vector>

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m); // n<=m
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (a[i] == b[j])
            i++; // 只要b[j]第一次匹配到a[i]，i向后移动一位，类似贪心的思想
        j++;     // 无论是否匹配成功，j向后移动一位
    }

    if (i == n)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
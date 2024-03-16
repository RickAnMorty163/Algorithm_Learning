#include <iostream>
#include <vector>

using namespace std;

signed main()
{
    ios::sync_with_stdio(false); // 关闭缓冲区,提高cin的效率

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    vector<int> s(n + 1); // 前缀和数组

    for (int i = 1; i <= n; i++)
        cin >> a[i]; // 注意下标从1开始

    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i]; // 前缀和数组初始化

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << "\n"; // 输出第l到第r个元素的和
    }

    return 0;
}
// notice:其中s数组是不必要的，可以在原数组a上直接构造，此处为了逻辑清晰，才使用了s数组
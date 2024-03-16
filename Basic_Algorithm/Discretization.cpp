#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pit;

int n, m;
const int N = 300010; // 需要处理的下标数量最多为 n+l+r = n+2m

int a[N], s[N]; // a[N]储存离散化后的值，s[N]储存前缀和

vector<int> alls;       // 存储所有待离散化的下标
vector<pit> add, query; // add,query分别存储插入操作和查询的区间

// 二分求x对应的离散化后的值(下标)
int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1; // 从1开始映射a[N]，方便前缀和数组处理
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;

        add.push_back({x, c});

        alls.push_back(x); // 将x存入待离散化数组
    }

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;

        query.push_back({l, r});

        alls.push_back(l);
        alls.push_back(r);
    }

    // 调整去重，实现所有待处理下标->alls下标(从0开始)的映射
    sort(alls.begin(), alls.end());
    auto repeatEND = unique(alls.begin(), alls.end());
    // std::unique 对升序序列进行遍历判断，依次将不重复元素取出放到前面，并返回一个迭代器，指向不重复部分的下一个位置
    alls.erase(repeatEND, alls.end()); // 删除末尾元素

    // 处理插入
    for (auto item : add)
    {
        int x = find(item.first); // 找到x映射的alls下标的下一位
        a[x] += item.second;      // a[N]对应+c
    }

    // 预处理前缀和
    for (int i = 1; i <= alls.size(); i++)
        s[i] = s[i - 1] + a[i];

    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second); // 找到映射后的询问区间(从1开始);
        cout << s[r] - s[l - 1] << "\n";
    }

    return 0;
}
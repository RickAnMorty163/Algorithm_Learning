#include <iostream>
#include <vector>
using namespace std;

const int N = 10 + 10e5;

vector<int> arr(N);

int left_bound(int l, int r, int target)
{
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (arr[mid] >= target)
            r = mid; // C1:arr[i]<k c2:arr[i]>=k 初始位置转化为求C2的左边界
        else
            l = mid + 1;
    }
    return l;
}
int right_bound(int l, int r, int target)
{
    while (l < r)
    {
        int mid = (l + r + 1) >> 1; // 避免r-l=1时出现死循环
        if (arr[mid] <= target)
            l = mid; // C1:arr[i]<=k c2:arr[i]>k 结束位置转化为求C1的右边界
        else
            r = mid - 1;
    }
    return l;
}

pair<int, int> binary_search(int l, int r, int target)
{

    int i = left_bound(l, r, target), j = right_bound(l, r, target);

    return make_pair(i, j);
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    while (q--)
    { // q==0时bool值为false退出while循环
        int k;
        cin >> k;
        int begin = left_bound(0, n - 1, k); // C1:arr[i]<k c2:arr[i]>=k 初始位置转化为求C2的左边界
        if (arr[begin] != k)
            cout << "-1 -1" << endl; // 未找到边界返回 -1 -1
        else
            cout << begin << " " << right_bound(begin, n - 1, k) << endl; // C1:arr[i]<=k c2:arr[i]>k 结束位置转化为求C1的右边界
    }
}
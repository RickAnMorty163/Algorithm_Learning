#pragma optimize(3)//
#include <iostream>

using namespace std;

const int N = 1000010;

int a[N], q[N]; // q[N]存储当前滑动窗口的下标(从0开始)
signed main()
{
    ios::sync_with_stdio(0);

    //----head---tail----
    int n, k; // k:滑动窗口长度
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // 滑动窗口最小值
    for (int i = 0, head = 0, tail = -1; i < n; i++)
    {
        // 判断队头是否滑出
        if (head <= tail && i - k + 1 > q[head])//根据i计算得到的head的下标大于等于实际下标时，队头元素滑出
            head++;

        while (head <= tail && a[i]<=a[q[tail]])
            tail--; // 新入队元素小于等于队尾元素则tail出队，新元素替换tail入队，保持队列元素递增性

        q[++tail] = i;//tail入队，即tail向右移动一位同时在将该位置对应下标记录在q中

        if (i >= k - 1)//记录下标从0开始，故从k-1开始输出窗口最小值
            cout << a[q[head]] << " ";
    }

    cout << '\n';

    // 滑动窗口最大值(对称操作)
    for (int i = 0, head = 0, tail = -1; i < n; i++)
    {
        // 判断队头是否滑出
        if (head <= tail && i - k + 1 > q[head])
            head++;

        while (head <= tail && a[i] >= a[q[tail]])
            tail--; // 新入队元素大于等于队尾元素则tail出队，新元素替换tail入队，保持队列元素递减性

        q[++tail] = i;

        if (i >= k - 1)
            cout << a[q[head]] << " ";
    }
    cout << "\n";

    return 0;
}

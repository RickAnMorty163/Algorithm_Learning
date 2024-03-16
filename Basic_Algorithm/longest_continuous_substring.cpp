#include <iostream>
#include <vector>

using namespace std;

signed main() {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n), s(100010);//s:统计区间内数字出现的次数(模拟Hash)

    for (int i = 0; i < n; i++) cin >> a[i];

    int res = 0;//记录结果

    for (int front = 0, back = 0; front < n; front++) {
        //队列思想
        s[a[front]]++; //front往后走1，区间加入新的数字，相当于入队
        while (s[a[front]] > 1) {//出现重复数字(一定是入队的a[front]重复)，等价于a[front]!=a[back]
            s[a[back]]--;//back数量-1,当back与front重合时s[a[front]]-1,下一次判断退出循环
            back++;//出队
        }
        //循环结束后，back和front重合，区间长度为0

        res = max(res, front - back + 1);//更新区间长度res最大值
    }
    cout << res << "\n";
    return 0;
}
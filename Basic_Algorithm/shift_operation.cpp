#include <iostream>

using namespace std;

//x & -x =x & (~x+1) :获取x的最后一个1

int lowbit(int x) {
    return x & (~x + 1);
}

signed main() {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;

        int res = 0;
        while (x) x -= lowbit(x), res++;//如果x不为0，那么去掉最后一个1

        cout << res << " ";
    }
    return 0;
}
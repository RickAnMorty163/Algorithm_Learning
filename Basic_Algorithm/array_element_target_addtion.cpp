#include <iostream>
#include <vector>

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x;
    cin >> n >> m >> x;

    vector<int> A(n), B(m);

    for (int i = 0; i < n; i++) cin >> A[i];
    for (int j = 0; j < m; j++) cin >> B[j];

    //指针a向右移动，若要满足A[a]+B[b]>x且b取最小值,b只能向左移动，满足单调性
    for (int a = 0, b = m - 1; a < n; a++) {
        while (b >= 0 && A[a] + B[b] > x) b--;
        if (A[a] + B[b] == x) {
            cout << a << " " << b;
            break;
        }
    }
    //时间复杂度O(n+m)
    return 0;
}
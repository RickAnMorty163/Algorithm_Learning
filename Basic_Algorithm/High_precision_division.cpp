#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0; // 余数
    for (int i = A.size() - 1; i >= 0; i--)
    { // 从最高位开始
        r = 10 * r + A[i];
        C.push_back(r / b);
        r %= b; // 更新余数
    }
    // 得到的C为正序

    reverse(C.begin(), C.end()); // 调整容器C为逆序

    while (C.size() > 1 && C.back() == 0)
        C.pop_back(); // 如果结果的最高位为0，删除该位

    return C;
}

signed main()
{
    ios::sync_with_stdio(false);

    string a;
    int b;

    cin >> a >> b;

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');

    int r;
    auto C = Div(A, b, r);

    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << "\n";
    cout << r << "\n";
    return 0;
}
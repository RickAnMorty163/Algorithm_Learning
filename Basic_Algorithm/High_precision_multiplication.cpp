#include <iostream>
#include <vector>
#include <algorithm>
//高精度乘法（大数乘小数）
//C[i]=(A[i]*b+t)%10
//t=(A[i]*b+t)/10
using namespace std;

vector<int> mul(vector<int> &A, int &b) {
    vector<int> C;
    if (b == 0) {
        C.push_back(0);
        return C;
    }//检查b=0的特殊情况
    int t = 0;
    for (int i = 0; i < A.size() || t; i++) {//截止条件：A到最高位或t不为0,可以省略下面的while循环
        if (i < A.size()) t += (A[i] * b);
        C.push_back(t % 10);
        t /= 10;
    }

    //while(t) {C.push_back(t%10);t/=10;}
    return C;
}

int main() {
    string a;
    int b;

    cin >> a >> b;

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

    auto C = mul(A, b);

    for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
}
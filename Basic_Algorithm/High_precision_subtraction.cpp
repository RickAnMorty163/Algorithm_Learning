#include<iostream>
#include <vector>

using namespace std;

//判断A,B的大小
bool cmp(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size()) return (A.size() > B.size());
    //如果A,B的大小相等，从最高位开始比较
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] != B[i]) return (A[i] > B[i]);
    }
    return true;//A=B
}

vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    //模拟减法运算
    //A[i]>=B[i] C[i] = A[i]-B[i]-t
    //A[i]<B[i] C[i] = A[i]+10-B[i]-t = A[i]-B[i]-t+10

    for (int i = 0, t = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        //t=A[i]-B[i]-t
        C.push_back((t + 10) % 10);//若t>=0,返回t本身，若t<0,返回t+10
        if (t < 0) t = 1;
        else t = 0;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();//如果结果大于一位数且有0占位，删除末尾的0
        return C;
}


int main() {
    string a, b;
    vector<int> A, B;

    cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - 48);
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    if (cmp(A, B)) {
        vector<int> C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    } else {
        cout << "-";
        vector<int> C = sub(B, A);
        for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    }
}
#include<iostream>
#include <vector>
using namespace std;

const int N=10e6+10;

vector<int> add(vector<int> &A,vector<int> &B){
    vector<int> C;
    //模拟加法原理:当前位i的值为 A[i]+B[i]+进位t
    int t=0;//进位，第零位没有进位，所以初始化为0
    for(int i=0;i<A.size()||i<B.size();i++){//截止条件到A和B的最高位
        if(i<A.size()) t+=A[i];
        if(i<B.size()) t+=B[i];
        C.push_back(t%10);//当前位为t的%10
        t/=10;//更新进位
    }
    if (t) C.push_back(1);//若最高位还有进位（t!=0），C末尾补上一位1
    return C;
}


int main(){
    string a,b;
    vector<int>A,B;

    cin>>a>>b;

    //模拟加法运算从个位开始处理，故将整数逆序存储在vector A,B中
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-48);//逆序存储大数 a[i]-'0'表示字符x与0的ASCII码之差,表示成a[i]-48也可
    for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');

    auto C=add(A,B);//C接受add(A,B)的返回值

    for(int i=C.size()-1;i>=0;i--) cout<<C[i];//还原为正序输出
}
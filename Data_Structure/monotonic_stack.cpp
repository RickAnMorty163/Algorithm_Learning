#include<iostream>
#include<stack>
using namespace std;

const int N=100010;

int n;
int stk[N],top;

signed main(){
    cin>>n;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        while(top&&stk[top]>=x) top--;//栈顶元素大于x则弹出栈顶元素
        if(top) cout<<stk[top]<<" ";
        else cout<<-1<<" ";

        stk[++top]=x;
    }

    return 0;
    
    
}


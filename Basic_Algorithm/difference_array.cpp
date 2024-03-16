#include<iostream>
#include<vector>

using namespace std;

const int N=100010;
//差分数组：构造一个数组b,若b的前缀和数组为a，则b为a的差分数组
void insert(vector<int>&b,int l,int r,int c){
    b[l]+=c;//差分数组编号为l的元素+c，则对应的前缀和数组从l开始每一项元素都+c
    b[r+1]-=c;//抵消编号r之后的元素改变
}
signed main(){

    ios::sync_with_stdio(false);

    int n,m;
    vector<int>a(N),b(N);//a为原数组，b为差分数组

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++) insert(b,i,i,a[i]);
    //初始化差分数组b，等价于对差分数组b的第i个位置(区间[i,i])上进行一次insert操作,
    //就可以让前缀和数组a的对应位置i的值被初始化为a[i]

    while(m--){
        int l,r,c;
        cin>>l>>r>>c;
        insert(b,l,r,c);//根据 l，r和c 对差分数组b进行一次操作
    }

    for(int i=1;i<=n;i++) b[i]+=b[i-1];//将差分数组b还原为前缀和数组

    for(int i=1;i<=n;i++) cout<<b[i]<<" ";//输出m次操作后得到的前缀和数组

    return 0;
}
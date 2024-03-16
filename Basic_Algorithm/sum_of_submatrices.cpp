#include<iostream>
#include<vector>

using namespace std;

signed main(){
    ios::sync_with_stdio(false);

    int n,m,q;
    cin>>n>>m>>q;

    vector<vector<int>> a(n+1,vector<int>(m+1));
    vector<vector<int>> s(n+1,vector<int>(m+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    }

    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]<<"\n";
    }

    return 0;
}
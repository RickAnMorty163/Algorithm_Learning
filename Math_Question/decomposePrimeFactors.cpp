#include<iostream>

using namespace std;

void decomposePrimeFactors(int x){
    for(int i =2 ;i<=x/i;i++){
        if(x%i==0){
            int s=0;
            while(x%i==0){
                x/=i,s++;
            }
            cout<<i<<" "<<s<<"\n";
        }
    }
    if(x>1) cout<<x<<" "<<"1\n";
    cout<<"\n";
}

signed main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        decomposePrimeFactors(x);
    }

    return 0;
}

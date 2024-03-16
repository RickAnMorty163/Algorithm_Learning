#include<iostream>
#include<cmath>
using namespace std;

double n;

double fbsSearch(double l,double r,double eps){
    while(r-l>eps){
        double mid=(l+r)/2;
        if(pow(mid,3)>=n) r=mid;
        else l=mid;
    }
    return l;
}

int main(){
    cin>>n;//high_precision_addition
    printf("%.6lf",fbsSearch(-22,22,1e-10));//保留n位小数，一般eps设置为1e-(n+2) 10000^(1/3)<22
}
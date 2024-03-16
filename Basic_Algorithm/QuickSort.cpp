//
// Created by 李想 on 2024/1/22.
//
#include<iostream>
using namespace std;
void quick_sort(int arr[],int left,int right){
    if(left>=right) return;
    int mid=arr[(left+right)/2],i=left-1,j=right+1;
    while(i<j){
        do i++;while(arr[i]<mid);
        do j--;while(arr[j]>mid);
        if(i<j) swap(arr[i],arr[j]);
    }
    quick_sort(arr,left,j);//排序完一轮后j在左边，j+1在右边
    quick_sort(arr,j+1,right);
}
int main(){
    int N;
    cin>>N;
    int* arr=new int[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    quick_sort(arr,0,N-1);
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    delete[] arr;
    arr= nullptr;
}
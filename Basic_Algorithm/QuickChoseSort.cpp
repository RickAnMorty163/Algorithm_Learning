#include<iostream>
using namespace std;
int quick_choose_sort(int arr[], int left, int right, int k) {
    if (left == right) return arr[left];//递归截止条件——区间长度为1，直接返回该元素
    int mid = arr[(left + right) / 2], i = left - 1, j = right + 1;
    while (i < j) {

        while (arr[++i] < mid);
        while (arr[--j] > mid);
        if (i < j) swap(arr[i], arr[j]);

    }
    //每次根据k的值来判断是左区间还是右区间递归
    int sl = j - left + 1;
    if (k <= sl) { return quick_choose_sort(arr, left, j, k); }
    else return quick_choose_sort(arr, j + 1, right, k - sl);//如果k在右边，则只进入右半部分递归，注意k要减去左半部分的长度
}
int main() {
    int N = 0, k = 0;
    cin >> N >> k;
    int *arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << quick_choose_sort(arr, 0, N - 1, k);
    delete[] arr;
    arr = nullptr;
}
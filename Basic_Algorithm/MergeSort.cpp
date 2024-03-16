//
// Created by 李想 on 2024/1/25.
//
#include <iostream>
using namespace std;
void merge_sort(int arr[], int left, int right)
{
    if (left >= right)
        return; // 检查左右区间是否合法
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right); // 划分左右区间
    // 归并
    int *temp = new int[right - left + 1]; // 辅助数组temp，长度等于区间长度
    int k = 0, i = left, j = mid + 1;      // 双指针i,j对对两个区间进行合并,k为辅助数组temp的下标
    while (i <= mid && j <= right)
    { // 防止越界
        // 双指针算法
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++]; // 若左半边还有剩余元素，直接复制到temp中
    while (j <= right)
        temp[k++] = arr[j++]; // 若右半边还有剩余元素，直接复制到temp中
    // 将temp中的数据复制回arr中
    for (i = left, j = 0; i <= right; i++, j++)
        arr[i] = temp[j];
    delete[] temp;
    temp = nullptr;
}
int main()
{
    int N;
    cin >> N;
    int *arr = new int[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    merge_sort(arr, 0, N - 1);
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    delete[] arr;
    arr = nullptr;
}
/**
 * @file 归并排序.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-28
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 1e6 + 5;
int a[N], tmp[N];

void merge_sort(int a[], int l, int r)
{
    if (l >= r) return ;
    
    int mid = l + r >> 1;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);

    int k = 1, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (a[i] <= a[j]) tmp[k ++] = a[i ++];
        else tmp[k ++] = a[j ++];
    while (i <= mid) tmp[k ++] = a[i ++];
    while (j <= r) tmp[k ++] = a[j ++];

    for (i = l, j = 1; i <= r; i ++, j ++) a[i] = tmp[j];
}

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    merge_sort(a, 1, n);
    
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}
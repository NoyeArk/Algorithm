/**
 * @file 快速排序.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-18
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int a[N];

void quick_sort(int a[], int l, int r)
{
    if (l >= r) return ;
    // 求分界点
    int k = a[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j)
    {
        do i ++; while (a[i] < k);
        do j --; while (a[j] > k);
        if (i < j) swap(a[i], a[j]);
    }
    quick_sort(a, l, j);
    quick_sort(a, j + 1, r);
}

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    quick_sort(a, 1, n);

    for (int i = 1; i <= n; i ++) cout << a[i] << " ";
    return 0;
}
/**
 * @file 归并排序.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-07
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int n;
int a[N], tmp[N];

void merge_sort(int l, int r)
{
    if (l >= r) return ;
    int mid = l + r >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (a[i] <= a[j]) tmp[++ k] = a[i ++];
        else tmp[++ k] = a[j ++];
    while (i <= mid) tmp[++ k] = a[i ++];
    while (j <= r) tmp[++ k] = a[j ++];

    for (i = l, j = 1; j <= k; i ++, j ++)
        a[i] = tmp[j];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];

    merge_sort(1, n);

	for (int i = 1; i <= n; i ++) cout << a[i] << " ";
	return 0;
}
/**
 * @file 787. 归并排序.cpp
 * @author horiki
 * @date 2024-09-20
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int n, a[N], tmp[N];

void sort(int l, int r)
{
    if (l >= r) return ;
    int mid = l + r >> 1;
    sort(l, mid); sort(mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
        if (a[i] <= a[j]) tmp[++ k] = a[i ++];
        else tmp[++ k] = a[j ++];
    while (i <= mid) tmp[++ k] = a[i ++];
    while (j <= r) tmp[++ k] = a[j ++];

    for (i = l, j = 1; j <= k; i ++, j ++) a[i] = tmp[j];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(1, n);
    for (int i = 1; i <= n; i ++) cout << a[i] << " ";
    return 0;
}
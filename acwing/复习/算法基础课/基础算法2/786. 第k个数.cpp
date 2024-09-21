/**
 * @file 786. 第k个数.cpp
 * @author horiki
 * @date 2024-09-20
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int n, k, a[N];

void sort(int l, int r)
{
    if (l >= r) return ;
    int k = a[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j)
    {
        do i ++; while (a[i] < k);
        do j --; while (a[j] > k);
        if (i < j) swap(a[i], a[j]);
    }
    sort(l, j); sort(j + 1, r);
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(1, n);
    cout << a[k];
    return 0;
}
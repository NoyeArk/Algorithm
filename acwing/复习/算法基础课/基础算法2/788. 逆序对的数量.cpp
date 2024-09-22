/**
 * @file 788. 逆序对的数量.cpp
 * @author horiki
 * @date 2024-09-21
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int n, a[N], tmp[N];
long long ans;

void sort(int l, int r)
{
    if (l >= r) return ;
    int mid = l + r >> 1;
    sort(l, mid); sort(mid + 1, r);

    int i = l, j = mid + 1, t = 0;
    while (i <= mid && j <= r)
        if (a[i] <= a[j]) tmp[++ t] = a[i ++];
        else
        {
            ans += mid - i + 1;
            tmp[++ t] = a[j ++];
        }
    while (i <= mid) tmp[++ t] = a[i ++];
    while (j <= r) tmp[++ t] = a[j ++];

    for (i = l, j = 1; j <= t; i ++, j ++) a[i] = tmp[j];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(1, n);
    cout << ans;
    return 0;
}
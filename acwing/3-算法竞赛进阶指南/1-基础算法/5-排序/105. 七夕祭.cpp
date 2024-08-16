/**
 * @file 105. 七夕祭.cpp
 * @author horiki
 * @date 2024-08-16
 * 
 * @brief 
 *  完全不知道该怎么做....
 */

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 100010;
int n, m, k;
int a[N], b[N];
LL c[N];

LL work(int *a, int n)
{
    LL ans = 0;
    for (int i = 1; i <= n; i ++) ans += a[i];
    ans /= n;
    for (int i = 1; i <= n; i ++) a[i] -= ans;

    c[1] = 0;
    for (int i = 2; i <= n; i ++) c[i] = c[i - 1] + a[i];
    sort(c + 1, c + 1 + n);
    
    int mid = c[n / 2 + 1];
    LL sum = 0;
    for (int i = 1; i <= n; i ++) sum += abs(c[i] - mid);
    return sum;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i ++)
    {
        int l, r; cin >> l >> r;
        a[l] ++, b[r] ++;
    }

    if (k % n && k % m) cout << "impossible";
    else if (k % n) cout << "column " << work(b, m);
    else if (k % m) cout << "row " << work(a, n);
    else cout << "both " << work(a, n) + work(b, m);

    return 0;
}
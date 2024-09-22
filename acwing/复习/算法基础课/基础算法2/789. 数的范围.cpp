/**
 * @file 789. 数的范围.cpp
 * @author horiki
 * @date 2024-09-21
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];

int main()
{
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    while (q --)
    {
        int k; cin >> k;
        int mi = lower_bound(a + 1, a + 1 + n, k) - a;
        int mx = upper_bound(a + 1, a + 1 + n, k) - a;
        if (a[mi] != k) cout << "-1 -1" << endl;
        else cout << mi - 1 << " " << mx - 2 << endl;
    }

    return 0;
}
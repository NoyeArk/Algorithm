/**
 * @file 789. 数的范围.cpp
 * @author horiki
 * @date 2024-09-12
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
    for (int i = 0; i < n; i ++) cin >> a[i];
    while (q --)
    {
        int x; cin >> x;
        int l = lower_bound(a, a + n, x) - a, r = upper_bound(a, a + n, x) - a;
        if (l != n && a[l] == x) cout << l << " " << r - 1 << endl;
        else cout << "-1 -1" << endl;
    }

    return 0;
}
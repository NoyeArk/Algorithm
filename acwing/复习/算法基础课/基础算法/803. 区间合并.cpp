/**
 * @file 803. 区间合并.cpp
 * @author horiki
 * @date 2024-09-14
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <utility>
#include <limits.h>
#include <algorithm>
using namespace std;

const int N = 100010;
pair<int, int> a[N];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + 1 + n);
    int mx = INT_MIN, ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (mx < a[i].first) mx = a[i].second, ans ++;
        else mx = max(mx, a[i].second);
    }
    cout << ans;
    return 0;
}
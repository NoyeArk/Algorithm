/**
 * @file 排队打水.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-15
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  感觉就是贪心呀，先让打水时间最少的打
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N], pre[N];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i < n; i ++) pre[i] = pre[i - 1] + a[i];

    long long ans = 0;
    for (int i = 1; i < n; i ++) ans += pre[i];

    cout << ans;
    return 0;
}
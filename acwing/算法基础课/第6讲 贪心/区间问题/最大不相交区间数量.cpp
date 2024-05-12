/**
 * @file 最大不相交区间数量.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-12
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  先按右端点从小到大排序 然后判断右端点
 */

#include <iostream>
#include <utility>
#include <algorithm>
#define st first 
#define ed second 
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
PII q[N];

bool cmp(PII a, PII b)
{
    return a.ed < b.ed;
}

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> q[i].st >> q[i].ed;

    sort(q + 1, q + 1 + n, cmp);

    int ed = -2e9, ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        auto [l, r] = q[i];
        if (l > ed) ans ++, ed = r;
    }
    cout << ans;
    return 0;
}
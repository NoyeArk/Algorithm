/**
 * @file 区间选点.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-09
 * @copyright Copyright (c) 2024
 * 
 * @brief
 *  1.将每个区间按右端点从小到大排序
 *  2.从前往后依次枚举每个区间
 *      如果当前区间中已经包含点，直接pass
 *      否则，选择当前区间的右端点
 */

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

#define r first 
#define l second

const int N = 100010;
pair<int, int> q[N];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> q[i].l >> q[i].r;
    sort(q + 1, q + 1 + n);

    int ed = -1e9 - 1, ans = 0;
    for (int i = 1; i <= n; i ++)
        if (q[i].l > ed)
            ed = q[i].r, ans ++;
    cout << ans;
    return 0;
}
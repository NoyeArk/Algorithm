/**
 * @file 区间覆盖.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-14
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  问题是选中一个之后，怎么尽可能判断是否能最大范围覆盖多的区间？
 *  1.将所有区间按左端点按照从小到大排序
 *  2.从前向后依次枚举每个区间，选择能够覆盖左端点的区间中，右端点最大的一个
 *      将start更新为右端点的最大值
 */

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
PII q[N];

int main()
{
    int s, t; cin >> s >> t;
    int n; cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> q[i].first >> q[i].second;

    sort(q + 1, q + 1 + n);

    int max_r = -2e9, ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (s < q[i].second) 
        {
            ans ++;
            max_r = q[i].second;
        }
    }

    return 0;
}
/**
 * @file 有向图的拓扑序列.cpp
 * @author horiki
 * @version 0.2
 * @date 2024-04-30 2024-05-11
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *     =维护一个队列，先把入度为0的点全部放进去，然后从队列中不断取出点
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int h[N], e[N], ne[N], idx;
int q[N], d[N];
int n, m;

bool top_sort()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i ++)
        if (!d[i]) q[++ tt] = i;
    while (hh <= tt)
    {
        int t = q[hh ++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (-- d[j] == 0) q[++ tt] = j;
        }
    }
    return tt == n - 1;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m --)
    {
        int x, y; cin >> x >> y;
        e[idx] = y, ne[idx] = h[x], h[x] = idx ++, d[y] ++;
    }

    if (top_sort())
        for (int i = 0; i < n; i ++) cout << q[i] << " ";
    else cout << -1;

    return 0;
}
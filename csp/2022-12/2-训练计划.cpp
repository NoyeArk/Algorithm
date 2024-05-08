/**
 * @file 2-训练计划.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-08
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 370;
int n, m, pre[N];
int h[N], e[N], ne[N], w[N], p[N], idx;

int q[N], d[N];

void insert(int a, int b, int v)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = v, h[a] = idx ++;
}

void top_sort()
{
    int hh = 0, tt = -1;
    q[++ tt] = 0;
    while (hh <= tt)
    {
        int t = q[hh ++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j] --;
            p[i] = max(p[i], )
            if (d[j] <= 0) p[i] = max(w[i], ) 
        }
    }
}

int main()
{
    insert(0, 0, 0);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) cin >> pre[i];
    {
        int x; cin >> x;
        insert(x, i);
    }

    for (int i = 1; i <= m; i ++)
    {
        int w; cin >> w;
        insert(pre[i], i, w);
        if (pre[i] != 0) d[i] ++;
    }

    top_sort();

    return 0;
}
/**
 * @file 853. 有边数限制的最短路 7.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-08
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 100010;
int n, m, k;
int dist[N], backup[N];
struct Edge
{
    int a, b, c;
}edges[M];

void bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 1; i <= k; i ++)
    {
        memcpy(backup, dist, sizeof dist);
        for (int j = 1; j <= m; j ++)
        {
            auto e = edges[j];
            dist[e.b] = min(dist[e.b], backup[e.a] + e.c);
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++)
    {
        int a, b, c; cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }

    bellman_ford();
    if (dist[n] > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << dist[n];

    return 0;
}
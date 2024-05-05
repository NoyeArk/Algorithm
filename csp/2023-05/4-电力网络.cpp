/**
 * @file 4-电力网络.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-05
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  
 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 10010, INF = 0x3f3f3f3f;
int n, m, k;
int g[N][N], dist[N];
bool st[N];
int cost[N][15];

int prim()
{
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for (int i = 0; i < n; i ++)
    {
        int t = -1;
        // 找出当前未合并的点中距离最小的点
        for (int j = 0; j < n; j ++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        if (i && dist[t] == INF) return INF;

        st[t] = true;
        if (i) res += dist[t];

        for (int j = 0; j < n; j ++)
            dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main()
{
    memset(g, 0x3f, sizeof g);
    cin >> n >> m >> k;
    // 读入n个城镇提供的k个变电站信息
    for (int i = 0; i < n; i ++)
        for (int j = 1; j <= k; j ++) 
            cin >> cost[i][j];
    // 读入m条输电线路
    for (int i = 1; i <= m; i ++)
    {
        int u, v; cin >> u >> v;
        int tmp = 0x3f3f3f3f;
        for (int a = 1; a <= k; a ++)
            for (int b = 1; b <= k; b ++)
            {
                // 从u的变电站a到v的变电站b的边权
                int w; cin >> w;
                // cout << "cmp:" << tmp << " " << cost[u][a] + cost[v][b] + w << endl;
                tmp = min(tmp, cost[u][a] + cost[v][b] + w);
            }
        g[u][v] = g[v][u] = tmp;
        // cout << tmp << endl;
    }
    // 求最小生成树
    cout << prim();
    return 0;
}
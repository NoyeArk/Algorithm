/**
 * @file 858. Prim算法求最小生成树 5.cpp
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

const int N = 510;
int n, m;
int g[N][N], dist[N];
bool st[N];

int prim()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    int res = 0;
    for (int i = 1; i <= n; i ++)
    {
        int t = -1;
        for (int j = 1; j <= n; j ++)
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        st[t] = true;
        res += dist[t];
        if (res > 0x3f3f3f3f / 2) return res;
        for (int j = 1; j <= n; j ++)
            dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main()
{
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    while (m --)
    {
        int a, b, c; cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int ans = prim();
    if (ans > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << ans;

    return 0;
}
/**
 * @file 858. Prim算法求最小生成树 6.cpp
 * @author horiki
 * @date 2024-09-12
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;
int n, m;
int dist[N], g[N][N];
bool st[N];

int prim()
{
    int res = 0;
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 1; i <= n; i ++)
    {
        int t = -1;
        for (int j = 1; j <= n; j ++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
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
    int res = prim();
    if (res > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << res;
    return 0;
}
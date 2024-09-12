/**
 * @file 849. Dijkstra求最短路 I 4.cpp
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
int g[N][N], dist[N];
bool st[N];

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n; i ++)
    {
        int t = -1;
        for (int j = 1; j <= n; j ++)
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        st[t] = true;
        for (int j = 1; j <= n; j ++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
}

int main()
{
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    while (m --)
    {
        int a, b, c; cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    dijkstra();
    if (dist[n] > 0x3f3f3f3f / 2) cout << -1;
    else cout << dist[n];
    return 0;
}
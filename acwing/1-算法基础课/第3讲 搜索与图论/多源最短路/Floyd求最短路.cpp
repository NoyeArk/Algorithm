/**
 * @file Floyd求最短路.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-08
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 210;
int dist[N][N];
int n, m, q;

void floyd()
{
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main()
{
    cin >> n >> m >> q;
    
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = 0x3f3f3f3f;

    while (m --)
    {
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }
    floyd();
    while (q --)
    {
        int x, y; cin >> x >> y;
        if (dist[x][y] > 0x3f3f3f3f / 2) cout << "impossible" << endl;
        else cout << dist[x][y] << endl;
    }
    return 0;
}
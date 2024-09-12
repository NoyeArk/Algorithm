/**
 * @file 854. Floyd求最短路 4.cpp
 * @author horiki
 * @date 2024-09-12
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 210;
int n, m, k;
int dist[N][N];

void floyd()
{
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = 0x3f3f3f3f3f;
    while (m --)
    {
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }
    floyd();
    while (k --)
    {
        int a, b; cin >> a >> b;
        if (dist[a][b] > 0x3f3f3f3f / 2) cout << "impossible" << endl;
        else cout << dist[a][b] << endl;
    }

    return 0;
}
/**
 * @file 走迷宫.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-11
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  
 */

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> PII;

const int N = 110;
int g[N][N], n, m;
int d[N][N];

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool st[N][N];

int bfs()
{
    queue<PII> q; q.push({1, 1});
    st[1][1] = true;
    while (q.size())
    {
        auto p = q.front(); q.pop();
        for (int i = 0; i < 4; i ++)
        {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if (x < 1 || x > n || y < 1 || y > m || st[x][y] || g[x][y] == 1) continue;
            d[x][y] = d[p.first][p.second] + 1;
            st[x][y] = true;
            q.push({x, y});
        }
    }
    return d[n][m];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> g[i][j];

    cout << bfs();
    return 0;
}
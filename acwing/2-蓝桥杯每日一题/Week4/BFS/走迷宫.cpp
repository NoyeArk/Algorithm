/**
 * @file 走迷宫.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-26
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	运行时间：31ms 运行空间：348KB
 */

#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;

const int N = 110;
int n, m;
int g[N][N], dist[N][N];

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int bfs()
{
	memset(dist, -1, sizeof dist);
	queue<PII> q;
	q.push({1, 1});
	dist[1][1] = 0;

	while (q.size())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i ++)
		{
			int a = x + dx[i], b = y + dy[i];
			if (a < 1 || a > n || b < 1 || b > m || dist[a][b] != -1 || g[a][b] == 1)
				continue;
			dist[a][b] = dist[x][y] + 1;
			if (a == n && b == m) return dist[a][b];
			q.push({a, b});
		}
	}
	return dist[n][m];
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
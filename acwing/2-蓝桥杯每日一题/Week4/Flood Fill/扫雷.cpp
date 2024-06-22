/**
 * @file 扫雷.cpp
 * @author horiki
 * @version 0.2
 * @date 2024-05-28 2024-06-11
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 310;
int n;
char g[N][N];
int st[N][N];

const int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

void dfs(int x, int y)
{
	int t = st[x][y];
	st[x][y] = -1;
	if (t) return ;
	for (int i = 0; i < 8; i ++)
	{
		int u = x + dx[i], v = y + dy[i];
		if (u < 1 || u > n || v < 1 || v > n || st[u][v] == -1) continue;
		dfs(u, v);
	}
}

int main()
{
	int k; cin >> k;
	for (int t = 1; t <= k; t ++)
	{
		cin >> n;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				cin >> g[i][j];

		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
			{
				if (g[i][j] == '*') st[i][j] = -1;
				else 
				{
					st[i][j] = 0;
					for (int u = 0; u < 8; u ++)
					{
						int x = i + dx[u], y = j + dy[u];
						if (x < 1 || x > n || y < 1 || y > n) continue;
						if (g[x][y] == '*') st[i][j] ++;
					}
				}
			}

		int ans = 0;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				if (!st[i][j]) 
				{
					dfs(i, j);
					ans ++;
				}

		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				if (st[i][j] != -1) ans ++;

		printf("Case #%d: %d\n", t, ans);

	}
	return 0;
}
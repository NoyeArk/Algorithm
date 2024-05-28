/**
 * @file 扫雷.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-28
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <queue>
#include <cstring>
#include <utility>

#define x first
#define y second
using namespace std;

typedef pair<int, int> PII;

const int N = 310;
int n;
char g[N][N];
bool st[N][N];

queue<PII> q;

const int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

bool check(int x, int y)
{
	for (int i = 0; i < 8; i ++)
	{
		int a = x + dx[i], b = y + dy[i];
		if (a < 1 || a > n || b < 1 || b > n) continue;
		if (g[a][b] != '.') return false;
	}
	return true;
}

void dfs(int x, int y)
{
	st[x][y] = true;
	for (int i = 0; i < 8; i ++)
	{
		int a = x + dx[i], b = y + dy[i];
		if (a < 1 || a > n || b < 1 || b > n) continue;
		if (!st[a][b] && check(a, b)) dfs(a, b);
		st[a][b] = true;
	}
}

int flood_fill()
{
	int res = 0;
	while (q.size())
	{
		auto p = q.front(); q.pop();
		if (st[p.x][p.y]) continue;
		res ++;
		st[p.x][p.y] = true;
		for (int i = 0; i < 8; i ++)
		{
			int a = p.x + dx[i], b = p.y + dy[i];
			if (a < 1 || a > n || b < 1 || b > n || st[a][b]) continue;
			st[a][b] = true;
		}
	}
	return res;
}

int rest_fill()
{
	int res = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			if (!st[i][j] && g[i][j] == '.')
				res ++;
	return res;
}

int main()
{
	int t; cin >> t;
	for (int k = 1; k <= t; k ++)
	{
		memset(st, 0, sizeof st);
		cin >> n;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				cin >> g[i][j];

		// for (int i = 1; i <= n; i ++)
		// 	for (int j = 1; j <= n; j ++)
		// 		if (check(i, j)) q.push({i, j});
		int ans = 0;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				if (!st[i][j] && check(i, j)) 
				{
					dfs(i, j);
					ans ++;
				}
		
		ans += rest_fill();
		printf("Case #%d: %d\n", k, ans);
	}

	return 0;
}
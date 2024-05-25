/**
 * @file 扫雷.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-25
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	把范围覆盖关系预处理为点与点之间的连接关系
 * 	这是一个有向图，但是感觉预处理需要花费O(n²)的复杂度，会TLE
 *  ------------------------------------------------------
 * 	遍历半径，r小于等于10，时间复杂度减少很多
 */

#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 50010, M = 999997;
struct Circle
{
	int x, y, r;
}cir[N];
LL h[M];
int id[M];
bool st[M];

LL get_key(int x, int y)
{
	return x * 1000000001ll + y;
}

int find(int x, int y)
{
	LL key = get_key(x, y);
	int t = (key % M + M) % M;

	while (h[t] != -1 && h[t] != key)
		if (++ t == M) t = 0;
	return t;
}

int sqr(int x)
{
	return x * x;
}

void dfs(int x, int y, int r)
{
	st[find(x, y)] = true;

	for (int i = x - r; i <= x + r; i ++)
		for (int j = y - r; j <= y + r; j ++)
			if (sqr(i - x) + sqr(j - y) <= sqr(r))
			{
				int t = find(i, j);
				if (id[t] && !st[t])
					dfs(i, j, cir[id[t]].r);
			}
}

int main()
{
	int n, m; cin >> n >> m;

	memset(h, -1, sizeof h);
	for (int i = 1; i <= n; i ++)
	{
		int x, y, r; cin >> x >> y >> r;
		cir[i] = {x, y, r};

		int t = find(x, y);
		h[t] = get_key(x, y);

		if (!id[t] || cir[id[t]].r < r)
			id[t] = i;
	}

	while (m --)
	{
		int x, y, r; cin >> x >> y >> r;
		for (int i = x - r; i <= x + r; i ++)
			for (int j = y - r; j <= y + r; j ++)
			{
				if (sqr(i - x) + sqr(j - y) <= sqr(r))
				{
					int t = find(i, j);
					if (id[t] && !st[t])
						dfs(i, j, cir[id[t]].r);
				} 
			}
	}

	int ans = 0;
	for (int i = 1; i <= n; i ++)
		if (st[find(cir[i].x, cir[i].y)])
			ans ++;

	cout << ans;
	return 0;
}
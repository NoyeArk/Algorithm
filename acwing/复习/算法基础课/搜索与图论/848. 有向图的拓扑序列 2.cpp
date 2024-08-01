/**
 * @file 848. 有向图的拓扑序列 2.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-01
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;
int d[N], q[N], hh, tt = -1;

bool top_sort()
{
	for (int i = 1; i <= n; i ++)
		if (!d[i]) q[++ tt] = i;
	while (hh <= tt)
	{
		auto t = q[hh ++];
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (-- d[j] == 0) q[++ tt] = j;
		}
	}
	return tt == n - 1;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while (m --)
	{
		int a, b; cin >> a >> b;
		e[idx] = b, ne[idx] = h[a], h[a] = idx ++, d[b] ++;
	}

	if (top_sort())
		for (int i = 0; i <= tt; i ++) cout << q[i] << " ";
	else cout << -1;

	return 0;
}
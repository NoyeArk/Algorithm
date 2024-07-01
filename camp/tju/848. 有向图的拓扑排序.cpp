/**
 * @file 848. 有向图的拓扑排序.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-07-01
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 100010;
int n, m;
int d[N], q[N], hh, tt = -1;
int h[N], e[N], ne[N], idx;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

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
			d[j] --;
			if (!d[j]) q[++ tt] = j;
		}
	}
	return tt + 1 == n;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while (m --)
	{
		int x, y; cin >> x >> y;
		add(x, y);
		d[y] ++;
	}

	if (top_sort())
	{
		for (int i = 0; i <= tt; i ++) cout << q[i] << " ";
	}
	else cout << -1;

	return 0;
}
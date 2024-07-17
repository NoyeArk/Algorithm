/**
 * @file 164. 可达性统计.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-07-17
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	先进行拓扑排序，然后用位运算记录访存的结点
 */

#include <iostream>
#include <cstring>
#include <bitset>

using namespace std;

const int N = 30010;
int n, m;
int q[N], hh, tt = -1;
int h[N], e[N], ne[N], d[N], idx;
bitset<N> f[N];

void top_sort()
{
	for (int i = 1; i <= n; i ++)
		if (!d[i]) q[++ tt] = i;
	while (hh <= tt)
	{
		int t = q[hh ++];
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (-- d[j] == 0) q[++ tt] = j;
		}
	}
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
	top_sort();
	for (int i = tt; ~i; i --)
	{
		int j = q[i];
		f[j][j] = 1;
		for (int k = h[j]; ~k; k = ne[k])
			f[j] |= f[e[k]];
	}
	for (int i = 1; i <= n; i ++) cout << f[i].count() << endl;
	return 0;
}
/**
 * @file 关键路径.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-29
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
int h[N], inverse_h[N], e[N], ne[N], w[N], idx;

int in_d[N], out_d[N];
int q[N], hh, tt = -1;

void add(int list[], int a, int b, int c)
{
	e[idx] = b, ne[idx] = list[a], w[idx] = c, list[a] = idx ++;
}

int ve[N];  // 顶点的最早发生时间
// 按照拓扑排序求解所有顶点的最早发生时间
void top_sort()
{
	hh = 0, tt = -1;
	for (int i = 1; i <= n; i ++)
		if (!in_d[i]) q[++ tt] = i;
	while (hh <= tt)
	{
		auto t = q[hh ++];
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			ve[j] = max(ve[j], ve[t] + w[i]);
			if (-- in_d[j] == 0) q[++ tt] = j;
		}
	}
	for (int i = 1; i <= n; i ++)
		printf("ver:%d ve:%d\n", i, ve[i]);
}

int vl[N];  // 求顶点的最迟发生时间
void inverse_top()
{
	memset(vl, 0x3f, sizeof vl);
	hh = 0, tt = -1;
	for (int i = 1; i <= n; i ++)
		if (!out_d[i]) q[++ tt] = i;
	vl[q[hh]] = ve[q[hh]];
	while (hh <= tt)
	{
		auto t = q[hh ++];
		for (int i = inverse_h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			vl[j] = min(vl[j], vl[t] - w[i]);
			if (-- out_d[j] == 0) q[++ tt] = j;
		}
	}
	for (int i = 1; i <= n; i ++)
		printf("ver:%d vl:%d\n", i, vl[i]);
}

int ee[N];  // 得到每个边的最早开始时间
void get_e()
{
	hh = 0, tt = -1;
	q[++ tt] = 1;
	while (hh <= tt)
	{
		auto t = q[hh ++];
		for (int i = h[t]; i != -1; i = ne[i])
			ee[i] = ve[t];
	}
	for (int i = 1; i <= n; i ++)
		printf("ver:%d vl:%d\n", i, vl[i]);
}

int main()
{
	memset(h, -1, sizeof h);
	memset(inverse_h, -1, sizeof inverse_h);
	cin >> n >> m;
	while (m --)
	{
		int a, b, c; cin >> a >> b >> c;
		add(h, a, b, c); add(inverse_h, b, a, c);
		out_d[a] ++, in_d[b] ++;
	}

	top_sort();
	cout << "--------" << endl;
	inverse_top();
	cout << "--------" << endl;
	get_e();

	return 0;
}
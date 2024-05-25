/**
 * @file Kruskal.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-25
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	运行时间：1133ms 运行空间：6104KB
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200010;
struct Edge
{
	int a, b, w;
}edges[N];
int n, m;
int pre[N];

bool cmp(Edge& x, Edge& y)
{
	return x.w < y.w;
}

int find(int x)
{
	return pre[x] = (pre[x] == x ? x : find(pre[x]));
}

int Kruskal()
{
	int res = 0, cnt = 0;
	for (int i = 1; i <= m; i ++)
	{
		auto e = edges[i];
		int a = find(e.a), b = find(e.b);

		if (a == b) continue;
		pre[a] = b;
		res += e.w, cnt ++;
	}
	return cnt < n - 1 ? 0x3f3f3f3f : res;
}

int main()
{
	cin >> n >> m;
	// 初始化并查集
	for (int i = 1; i <= n; i ++) pre[i] = i;

	for (int i = 1; i <= m; i ++) 
		cin >> edges[i].a >> edges[i].b >> edges[i].w;

	sort(edges + 1, edges + 1 + m, cmp);

	int ans = Kruskal();
	if (ans == 0x3f3f3f3f) cout << "impossible";
	else cout << ans;

	return 0;
}
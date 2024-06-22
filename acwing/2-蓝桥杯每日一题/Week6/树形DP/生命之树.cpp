/**
 * @file 生命之树.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-23
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	1.状态表示：f[u]表示以u为根的子树中结点值和的最大值
 * 	2.状态计算：
 * 		f[u] = w[u] + max(max(s1, 0), max(s2, 0), ... , max(sn, 0))
 */

#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 100010, M = 200010;
int h[N], e[M], ne[M], w[N], idx;
LL f[N];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int father)
{
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (j == father) continue;
		dfs(j, u);
		f[u] += max(0ll, f[j]);
	}
	f[u] += w[u];
}

int main()
{
	memset(h, -1, sizeof h);
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) cin >> w[i];
	for (int i = 1; i < n; i ++)
	{
		int a, b; cin >> a >> b;
		add(a, b); add(b, a);
	}

	dfs(1, -1);

	LL ans = f[1];
	for (int i = 2; i <= n; i ++)
		ans = max(ans, f[i]);

	cout << ans;
	return 0;
}
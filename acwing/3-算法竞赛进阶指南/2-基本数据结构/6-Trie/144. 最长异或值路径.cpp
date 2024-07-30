/**
 * @file 144. 最长异或值路径.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-07-30
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	先求出每个元素到根节点的异或和，然后转换为树中任意两个结点的最大异或和
 */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010, M = 200010;
int n;
int h[N], e[M], w[M], ne[M], cnt;
int a[N], son[3000000][2], idx;

void add(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void dfs(int u, int father, int sum)
{
	a[u] = sum;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (j != father) dfs(j, u, w[i] ^ sum);
	}
}

void insert(int x)
{
	int p = 0;
	for (int i = 30; ~i; i --)
	{
		int &s = son[p][x >> i & 1];
		if (!s) s = ++ idx;
		p = s;
	}
}

int query(int x)
{
	int p = 0, res = 0;
	for (int i = 30; ~i; i --)
	{
		int s = x >> i & 1;
		if (son[p][!s])
		{
			res += 1 << i;
			p = son[p][!s];
		}
		else p = son[p][s];
	}
	return res;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for (int i = 1; i < n; i ++)
	{
		int a, b, c; cin >> a >> b >> c;
		add(a, b, c); add(b, a, c);
	}

	dfs(0, -1, 0);

	for (int i = 0; i < n; i ++) insert(a[i]);

	int ans = 0;
	for (int i = 0; i < n; i ++)
		ans = max(ans, query(a[i]));

	cout << ans;
	return 0;
}
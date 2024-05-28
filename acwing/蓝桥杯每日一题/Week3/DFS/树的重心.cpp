/**
 * @file 树的重心.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-28
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010, M = 2 * N;
int h[N], e[M], ne[M], idx;
int ans, n;
bool st[N];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int dfs(int u)
{
	st[u] = true;
	int sum = 1, res = 0;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (st[j]) continue;
		int t = dfs(j);
		sum += t;
		res = max(res, t);
	}
	res = max(res, n - sum);
	ans = min(ans, res);
	return sum;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	ans = n;
	for (int i = 1; i <= n - 1; i ++)
	{
		int a, b; cin >> a >> b;
		add(a, b); add(b, a);
	}
	dfs(1);

	cout << ans;
	return 0;
}
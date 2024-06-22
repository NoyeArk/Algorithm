/**
 * @file 没有上司的舞会.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-19
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	状态转移方程：f[u][0] = max(f[])
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 6010;
int n;
bool d[N];
int f[N][2];
int happy[N];
int h[N], e[N], ne[N], idx;

void dfs(int u)
{
	f[u][1] = happy[u];
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		dfs(j);
		f[u][0] += max(f[j][0], f[j][1]);
		f[u][1] += f[j][0];
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> happy[i];
	for (int i = 1; i < n; i ++)
	{
		int l, k; cin >> l >> k;
		e[idx] = l, ne[idx] = h[k], h[k] = idx ++;
		d[l] = true;
	}

	int r = 1;
	while (d[r]) r ++;

	dfs(r);

	cout << max(f[r][0], f[r][1]);
	return 0;
}
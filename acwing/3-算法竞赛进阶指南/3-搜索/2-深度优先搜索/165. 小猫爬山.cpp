/**
 * @file 165. 小猫爬山.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-07-18
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	优先考虑决策少的元素
 */

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 20;
int n, w, ans = N;
int c[N], sum[N];

void dfs(int u, int k)
{
	if (k >= ans) return ;
	if (u == n) 
	{
		ans = k;
		return ;
	}
	for (int i = 0; i < k; i ++)
	{
		if (c[u] + sum[i] <= w)
		{
			sum[i] += c[u];
			dfs(u + 1, k);
			sum[i] -= c[u];
		}
	}
	sum[k] = c[u];
	dfs(u + 1, k + 1);
	sum[k] = 0;
}

int main()
{
	cin >> n >> w;
	for (int i = 0; i < n; i ++) cin >> c[i];
	sort(c, c + n, greater<int>());
	
	dfs(0, 0);

	cout << ans;
	return 0;
}
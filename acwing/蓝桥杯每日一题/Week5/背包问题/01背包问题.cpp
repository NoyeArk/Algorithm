/**
 * @file 01背包问题.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-20
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	1.状态表示：f[i][j]表示前i个物品中体积不超过j的最大价值
 * 	2.状态计算：
 * 		可将所有的集合划分为选第i个和不算第i个
 * 		2.1 选第i个物品
 * 			f[i][j] = f[i - 1][j - v[i]] + w[i]
 * 		2.2 不选第i个
 * 			f[i][j] = f[i - 1][j]
 */

#include <iostream>
using namespace std;

const int N = 1010;
int v[N], w[N];
int f[N];

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

	for (int i = 1; i <= n; i ++)
		for (int j = m; j >= 0; j --)
			if (j >= v[i]) 
				f[j] = max(f[j], f[j - v[i]] + w[i]);

	cout << f[m];
	return 0;
}
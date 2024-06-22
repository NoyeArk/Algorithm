/**
 * @file 石子合并.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-21
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	1.状态表示：f[i][j]表示合并区间[i, j)所需要的最小代价
 * 	2.状态计算：
 * 		|————————————————————————————————————|
 * 		i		f[i][k]	  k	 f[k + 1][j]	 j
 */

#include <iostream>
using namespace std;

const int N = 310;
int a[N], f[N][N];

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i], a[i] += a[i - 1];

	for (int len = 2; len <= n; len ++)
		for (int i = 1; i + len - 1 <= n; i ++)
		{
			int j = i + len - 1;
			f[i][j] = 1e8;
			for (int k = i; k < j; k ++)
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + a[j] - a[i - 1]);
		}

	cout << f[1][n];
	return 0;
}
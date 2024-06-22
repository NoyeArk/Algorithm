/**
 * @file 货币系统.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-03
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	1.状态表示：
 * 		f[i][j]表示1~i个物品中，还要凑出j元钱的方案数
 * 	2.状态计算：
 * 		不选第i个：
 * 		f[i][j] = f[i - 1][j] + 1
 * 		选1个第i个：
 * 		f[i][j] = f[i - 1][j - 1 * w[i]] + 1
 * 		选2个第i个：
 * 		f[i][j] = f[i - 1][j - 2 * w[i]] + 1
 * 		...
 * 		选n个第i个：
 * 		f[i][j] = f[i - 1][j - n * w[i]] + 1
 * 		
 * 		f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]], ..., f[i - 1][j - n * w[i]]) + 1
 * 		f[i][j - w[i]] = max(f[i - 1][j - w[i]], f[i - 1][j - 2 * w[i]], ..., f[i - 1][j - n * w[i]]) + 1
 * 
 * 		f[i][j] = max(f[i - 1][j], f[i][j - w[i]) + 1
 */

#include <iostream>
using namespace std;

typedef long long LL;

const int N = 30, M = 10010;
int w[N];
LL f[N][M];

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> w[i];

	f[0][0] = 1;
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j <= m; j ++)
		{
			f[i][j] = f[i - 1][j];
			if (j >= w[i])
				f[i][j] += f[i][j - w[i]];
		}

	cout << f[n][m];
	return 0;
}
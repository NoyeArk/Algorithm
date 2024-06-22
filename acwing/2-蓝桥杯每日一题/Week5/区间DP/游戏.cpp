/**
 * @file 游戏.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-24
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	自己的分值-对方分值差距最大
 * 	1.状态表示：
 * 		f[i][j]表示先手分值-后手分值的最大值
 * 		g[i] 表示玩家二第i次拿的分数
 * 	2.状态计算：
 * 		f[i][j] = max(Wi - f[i + 1][j], Wj - f[i][j - 1])
 * 	
 * 	第一重循环枚举区间长度
 * 	第二重循环枚举区间左端点
 */

#include <iostream>
using namespace std;

const int N = 110;
int w[N];
int f[N][N];

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) cin >> w[i];

	for (int len = 1; len <= n; len ++)
		for (int i = 1; i + len - 1 <= n; i ++)
		{
			int j = i + len - 1;
			f[i][j] = max(w[i] - f[i + 1][j], w[j] - f[i][j - 1]);
		}

	int sum = 0, d = f[1][n];
	for (int i = 1; i <= n; i ++)
		sum += w[i];

	cout << (sum + d) / 2 << " " << (sum - d) / 2;
	return 0;
}
/**
 * @file 糖果.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-11
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	一共有m种糖果，但是问题是让求最少需要购买多少包糖果
 * 	在DFS的过程中如何保证这个结果是最少的？
 * 	使用二分答案 + DFS ？
 * 	-----------------------------------
 * 	状态压缩DP：用一个数的二进制来表示一个合法的状态
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 110, M = 20;
int n, m, k;
int w[N][M], dp[1 << M];

int main()
{
	cin >> n >> m >> k;
	memset(dp, -1, sizeof dp);

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= k; j ++)
		{
			cin >> w[i][j];
		    w[i][j] --;
		}

	int tar = 1 << m;
	dp[0] = 0;
	for (int i = 1; i <= n; i ++)
	{
		int t = 0;
		for (int j = 1; j <= k; j ++) 
			t |= (1 << w[i][j]);
		// 得到这包糖果的状态表示t
		for (int u = 0; u < tar; u ++)
		{
			if (dp[u] == -1) continue;
			int v = u | t;
			if (dp[v] == -1 || dp[v] > dp[u] + 1)
				dp[v] = dp[u] + 1;
		}
	}

	cout << dp[tar - 1];
	return 0;
}
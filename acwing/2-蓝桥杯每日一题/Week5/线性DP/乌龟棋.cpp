/**
 * @file 乌龟棋.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-19
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	1.状态表示：f[i][5]表示走到第i个格子时每个卡片还剩多少张的情况下可以获得最大分数
 * 	2.状态计算
 * 		分析一下走到第i个格子可以怎么走？
 * 		一共有四种走法：1 2 3 4
 * 		如果有1的卡片：f[i] = f[i - 1]
 * 		如果有2的卡片：f[i] = f[i - 2]
 * 	------------------------------------------
 * 	1.状态表示：
 * 		1.1 集合：f[a, b, c, d]表示编号为1、2、3、4的卡分别使用了A、B、C、D张的方案的集合
 * 		1.2 属性：每一个方案分值的最大值
 *	2.状态计算
		f[i]
 */

#include <iostream>
using namespace std;

const int N = 400, M = 41;
int n, m;
int w[N], cnt[N];
int f[M][M][M][M];

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> w[i];
	for (int i = 1; i <= m; i ++)
	{
		int x; cin >> x;
		cnt[x] ++;
	}

	f[0][0][0][0] = w[1];
	for (int A = 0; A <= cnt[1]; A ++)
		for (int B = 0; B <= cnt[2]; B ++)
			for (int C = 0; C <= cnt[3]; C ++)
				for (int D = 0; D <= cnt[4]; D ++)
				{
					int score = w[1 + A + 2 * B + 3 * C + 4 * D];
					int &v = f[A][B][C][D];
					if (A) v = max(v, f[A - 1][B][C][D] + score);
					if (B) v = max(v, f[A][B - 1][C][D] + score);
					if (C) v = max(v, f[A][B][C - 1][D] + score);
					if (D) v = max(v, f[A][B][C][D - 1] + score);
				}

	cout << f[cnt[1]][cnt[2]][cnt[3]][cnt[4]];
	return 0;
}
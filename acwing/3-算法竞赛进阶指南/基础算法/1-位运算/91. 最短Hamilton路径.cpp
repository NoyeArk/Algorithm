/**
 * @file 91. 最短Hamilton路径.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-22
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	状态压缩
 */

#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 20, M = 1 << 20;
int weight[N][N], f[M][N];

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			cin >> weight[i][j];

	memset(f, 0x3f, sizeof f);
	f[1][0] = 0;

	for (int i = 0; i < 1 << n; i ++)
		for (int j = 0; j < n; j ++)
			if (i >> j & 1) 
				for (int k = 0; k < n; k ++)
					if (i - (1 << j) >> k & 1)
						f[i][j] = min(f[i][j], f[i - (1 << j)][k] + weight[k][j]);
	
	cout << f[(1 << n) - 1][n - 1];
	return 0;
}
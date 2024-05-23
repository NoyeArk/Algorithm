/**
 * @file 最长公共子序列.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-23
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	1.状态表示：f[i][j]表示串a以i结尾和串b以j结尾的子串的最长公共子序列的最大长度
 * 	2.状态计算：
 * 		A[i] == B[j]:
 * 			f[i][j] = f[i - 1][j - 1] + 1
 * 		A[i] != B[j]:
 * 			f[i][j] = max(f[i - 1][j], f[i][j - 1])
 */

#include <iostream>
using namespace std;

const int N = 1010;
char A[N], B[N];
int f[N][N];

int main()
{
	int n, m; cin >> n >> m >> A + 1 >> B + 1;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (A[i] == B[j]) f[i][j] = f[i - 1][j - 1] + 1;
			else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
	cout << f[n][m];
	return 0;
}
/**
 * @file 斐波那契.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-06
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	直接做肯定会超时
 * 	矩阵快速幂做法：
 * 		An-1 × F = An，其中F定义为[[0, 1], [1, 1]]
 * 		则An = A0 × F^n
 * 	时间复杂度：O(800 * logn)
 * 	运行时间：2ms	运行空间：216KB
 */

#include <iostream>
#include <cstring>
using namespace std;

const int mod = 10000;

void mul(int a[][2], int b[][2])
{
	int c[2][2] = { 0 };
	for (int i = 0; i < 2; i ++)
		for (int j = 0; j < 2; j ++)
			for (int k = 0; k < 2; k ++)
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
	memcpy(a, c, sizeof c);
}

int fib(int n)
{
	int a[2][2] = {0, 1, 0, 0};
	int f[2][2] = {0, 1, 1, 1};
	while (n)
	{
		if (n & 1) mul(a, f);
		mul(f, f);
		n >>= 1;
	}
	return a[0][0];
}

int main()
{
	int n;
	while (cin >> n, n != -1)
		cout << fib(n) << endl;

	return 0;
}
/**
 * @file 计算系数.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-10
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	相当于计算C(k, n)与a^n与b^m的乘积
 */

#include <iostream>
using namespace std;

typedef long long LL;

const int N = 1010, mod = 10007;
int C[N][N];

void init()
{
	for (int i = 0; i < N; i ++)
		for (int j = 0; j <= i; j ++)
			if (!j) C[i][j] = 1;
			else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
}

int qmi(int a, int k)
{
	int res = 1;
	while (k)
	{
		if (k & 1) res = (LL)res * a % mod;
		k >>= 1;
		a = (LL)a * a % mod;
	}
	return res;
}

int main()
{
	init();
	int a, b, k, n, m; cin >> a >> b >> k >> n >> m;

	cout << (LL)C[k][n] * qmi(a, n) % mod * qmi(b, m) % mod;
	return 0;
}
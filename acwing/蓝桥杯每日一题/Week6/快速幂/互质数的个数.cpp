/**
 * @file 互质数的个数.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-30
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	先求出a的b次方的值，然后用试除法判断两个数是否互质
 *  -----------------------------------------------
 * 	1~n中与n互质的个数称为欧拉函数
 * 	f(n) = n * (1 - 1 / p1) * (1 - 1 / p2) * ... * (1 - 1 / ps)
 * 	在分解质因数的过程中求解
 * 
 * 	f(a^b) = a^(b - 1) * f(a)
 */

#include <iostream>
using namespace std;

typedef long long LL;

const int mod = 998244353;

int qmi(LL a, LL k)
{
	LL res = 1;
	while (k)
	{
		if (k & 1) res = a * res % mod;
		k >>= 1;
		a = a * a % mod;
	}
	return res;
}

int main()
{
	LL a, b; cin >> a >> b;

	if (a == 1) 
	{
		cout << 0;
		return 0;
	}

	int ans = a, x = a;
	for (int i = 2; i <= x / i; i ++)
	{
		if (x % i == 0)
		{
			ans = (LL)ans / i * (i - 1) % mod;
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1) ans = (LL)ans / x * (x - 1) % mod;

	cout << (LL)ans * qmi(a, b - 1) % mod;
	return 0;
}
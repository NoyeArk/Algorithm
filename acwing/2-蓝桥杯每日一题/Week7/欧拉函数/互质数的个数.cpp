/**
 * @file 互质数的个数.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-06
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

typedef long long LL;

const int P = 998244353;

LL qmi(LL a, LL k)
{
	LL res = 1;
	while (k)
	{
		if (k & 1) res = res * a % P;
		k >>= 1;
		a = a * a % P;
	}
	return res;
}

int get_oular(LL x)
{
	LL res = x;
	for (LL i = 2; i * i <= x; i ++)
		if (x % i == 0)
		{
			res = res / i * (i - 1) % P;
			while (x % i == 0) x /= i;
		}
	if (x > 1) res = res / x * (x - 1) % P;
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

	cout << (LL)get_oular(a) * qmi(a, b - 1) % P;
	return 0;
}
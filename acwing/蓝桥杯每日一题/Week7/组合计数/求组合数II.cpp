/**
 * @file 求组合数II.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-20
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	此时a, b的范围变成了100000，如果直接进行求解，肯定会超时
 * 	并且数组太大，不能开这么大的数组
 * 	C(a, b) = a! / ((a - b)! * b!)
 */

#include <iostream>
using namespace std;

typedef long long LL;

const int N = 100010, mod = 1e9 + 7;
int fact[N], infact[N];

int qmi(int a, int k, int p)
{
	int res = 1;
	while (k)
	{
		if (k & 1) res = (LL)a * res % p;
		k >>= 1;
		a = (LL)a * a % mod;
	}
	return res;
}

void init()
{
	fact[0] = infact[0] = 1;
	for (int i = 1; i < N; i ++)
	{
		fact[i] = (LL)i * fact[i - 1] % mod;
		infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
	}
}

int main()
{
	init();
	int n; cin >> n;
	while (n --)
	{
		int a, b; cin >> a >> b;
		cout << (LL)fact[a] * infact[a - b] % mod * infact[b] % mod << endl;
	}
	return 0;
}
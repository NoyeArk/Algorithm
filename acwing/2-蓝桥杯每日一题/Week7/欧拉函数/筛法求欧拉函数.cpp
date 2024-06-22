/**
 * @file 筛法求欧拉函数.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-04
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	循环遍历1 ~ n中的每个数求欧拉函数会超时，时间复杂度：O(n*sqrt(n))
 */

#include <iostream>
using namespace std;

typedef long long LL;

const int N = 1000010;

int primes[N], cnt;
int phi[N];
bool st[N];

LL get_oular(int n)
{
	phi[1] = 1;
	for (int i = 2; i <= n; i ++)
	{
		if (!st[i])
		{
			primes[cnt ++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; primes[j] <= n / i; j ++)
		{
			st[primes[j] * i] = true;
			if (i % primes[j] == 0)
			{
				phi[primes[j] * i] = phi[i] * primes[j];
				break;
			}
			else phi[primes[j] * i] = phi[i] * (primes[j] - 1);
		}
	}

	LL res = 0;
	for (int i = 1; i <= n; i ++)
		res += phi[i];
	return res;
}

int get_oula(int x)
{
	int res = x;
	for (int i = 2; i <= x / i; i ++)
		if (x % i == 0)
		{
			res = res / i * (i - 1);
			while (x % i == 0) x /= i;
		}
	if (x > 1) res = res / x * (x - 1);
	return res;
}

int main()
{
	int n; cin >> n;

	// LL ans = 0;
	// for (int i = 1; i <= n; i ++)
	// 	ans += get_oula(i);

	// cout << ans;
	cout << get_oular(n);
	return 0;
}
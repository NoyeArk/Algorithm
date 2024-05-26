/**
 * @file 转圈游戏.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-26
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	求(x + 10^k * m) % n
 */

#include <iostream>
using namespace std;

typedef long long  LL;

int qmi(int m, int k, int p)
{
	int res = m;
	int a = 10;
	while (k)
	{
		if (k & 1) res = (LL)a * res % p;
		k >>= 1;
		a = (LL)a * a % p;
	}
	return res;
}

int main()
{
	int n, m, k, x; cin >> n >> m >> k >> x;
	cout << (x + qmi(m, k, n)) % n;

	return 0;
}
/**
 * @file 快速幂.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-25
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	运行时间：1550ms 运行空间：4312KB
 */

#include <iostream>
using namespace std;

typedef long long LL;

int qmi(int a, int k, int p)
{
	int res = 1;
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
	int n; cin >> n;
	while (n --)
	{
		int a, k, p; cin >> a >> k >> p;
		cout << qmi(a, k, p) << endl;
	}
	return 0;
}
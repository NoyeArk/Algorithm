/**
 * @file 包子凑数.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-08
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 10000;
int f[N], v[110];

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int n, d = 0; cin >> n;
	for (int i = 1; i <= n; i ++) 
	{
		cin >> v[i];
		d = gcd(d, v[i]);
	}

	if (d != 1)
	{
		cout << "INF";
		return 0;
	}

	f[0] = 1;
	for (int i = 1; i <= n; i ++)
		for (int j = v[i]; j < N; j ++)
			f[j] |= f[j - v[i]];
	
	int ans = 0;
	for (int i = 0; i < N; i ++)
		if (!f[i]) ans ++;

	cout << ans;
	return 0;
}
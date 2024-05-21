/**
 * @file 1-如此编码.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-20
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 25;
int a[N], b[N], c[N], tmp[N];

int main()
{
	int n, m; cin >> n >> m;
	c[0] = 1;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		c[i] = c[i - 1] * a[i];
	}

	for (int i = 1; i <= n; i ++)
	{
		tmp[i] = m % c[i];
		int ans = (tmp[i] - tmp[i - 1]) / c[i - 1];
		cout << ans << " ";
	}

	return 0;
}
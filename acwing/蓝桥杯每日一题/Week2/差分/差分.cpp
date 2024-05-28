/**
 * @file 差分.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-28
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int a[N], diff[N];

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i ++) 
	{
		cin >> a[i];
		diff[i] = a[i] - a[i - 1];
	}

	while (m --)
	{
		int l, r, c; cin >> l >> r >> c;
		diff[l] += c, diff[r + 1] -= c;
	}

	int ans = 0;
	for (int i = 1; i <= n; i ++)
	{
		ans += diff[i];
		cout << ans << " ";
	}

	return 0;
}
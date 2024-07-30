/**
 * @file 104. 货仓选址.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-07-30
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];

	sort(a + 1, a + 1 + n);

	int tar = n & 1 ? a[n / 2 + 1] : (a[n / 2] + a[n / 2 + 1]) / 2;
	
	int ans = 0;
	for (int i = 1; i <= n; i ++)
		ans += abs(a[i] - tar);

	cout << ans;
	return 0;
}
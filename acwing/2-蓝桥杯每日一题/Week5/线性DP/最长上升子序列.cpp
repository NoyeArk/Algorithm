/**
 * @file 最长上升子序列.cpp
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

const int N = 1010;
int a[N], f[N];

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];

	for (int i = 1; i <= n; i ++) f[i] = 1;

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j < i; j ++)
			if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);

	int ans = 0;
	for (int i = 1; i <= n; i ++) 
		ans = max(ans, f[i]);
		
	cout << ans;
	return 0;
}
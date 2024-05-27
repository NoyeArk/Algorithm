/**
 * @file 2-出行计划.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-27
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 300010;
int diff[N], pre[N];

int main()
{
	int n, m, k; cin >> n >> m >> k;
	int mx = 0;
	for (int i = 1; i <= n; i ++)
	{
		int t, c; cin >> t >> c;
		mx = max(mx, t);
		int l = max(1, t - c + 1), r = t;
		diff[l] ++, diff[r + 1] --;
	}

	for (int i = 1; i <= mx; i ++)
		pre[i] = pre[i - 1] + diff[i];

	for (int i = 1; i <= m; i ++) 
	{
		int q; cin >> q;
		cout << pre[q + k] << endl;
	}

	return 0;
}
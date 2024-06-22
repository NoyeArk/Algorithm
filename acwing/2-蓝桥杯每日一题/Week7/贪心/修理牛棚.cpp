/**
 * @file 修理牛棚.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-22
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	将s个牛棚最多划分为m个区间，使得这m个区间的长度和最小
 *  将距离相近的点划分到一个区间内
 *  --------------------------------------------------
 * 	倒着想，挖所有为0的区间，最多选m-1个区间
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 210;
int a[N], b[N];

int main()
{
	int m, s, c; cin >> m >> s >> c;
	for (int i = 1; i <= c; i ++) cin >> a[i];
	sort(a + 1, a + 1 + c);

	int ans = a[c] - a[1] + 1;
	for (int i = 1; i < c; i ++) 
		b[i] = a[i + 1] - a[i] - 1;

	sort(b + 1, b + c, greater<int>());
	for (int i = 1; i < c && i < m; i ++)
		ans -= b[i];

	cout << ans;
	return 0;
}
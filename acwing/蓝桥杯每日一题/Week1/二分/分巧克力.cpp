/**
 * @file 分巧克力.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-16
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  n的规模为100000，时间复杂度应为nlogn，使用二分
 */

#include <iostream>
using namespace std;

const int N = 100010;
int n, k;
int h[N], w[N];

bool check(int mid)
{
	// 判断最大边长为mid的巧克力块是否满足条件
	int res = 0;
	for (int i = 1; i <= n; i ++)
	{
		int a = h[i] / mid, b = w[i] / mid;
		res += a * b;
	}
	return res >= k;
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) cin >> h[i] >> w[i];

	int l = 1, r = 100000;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}

	cout << r;
	return 0;
}
/**
 * @file 102. 最佳牛围栏.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-07-28
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	10^5：时间复杂度O(nlogn)
 */

#include <iostream>
#include <math.h>
using namespace std;

const int N = 100010;
int n, f, a[N];
double pre[N];

bool check(double mid)
{
	for (int i = 1; i <= n; i ++)
		pre[i] = pre[i - 1] + a[i] - mid;

	double mi = 2e9;
	for (int i = f, j = 0; i <= n; i ++, j ++)
	{
		mi = min(mi, pre[j]);
		if (pre[i] - mi >= 0) return true;
	}
	return false;
}

int main()
{
	cin >> n >> f;
	for (int i = 1; i <= n; i ++) cin >> a[i];

	double l = 1, r = 2000;
	while (r - l > 1e-5)
	{
		double mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}

	printf("%.0lf", floor(r * 1000));
	return 0;
}
/**
 * @file 最佳牛围栏.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-24
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	check函数核心：用每个数都减去平均值mid，判断存不存在一个连续的区间的和≥0
 */

#include <iostream>
#include <cmath>
using namespace std;

const int N = 100010;
int n, f;
int a[N];
double pre[N];

bool check(double mid)
{
	for (int i = 1; i <= n; i ++)
		pre[i] = pre[i - 1] + a[i] - mid;

	double mins = 2e9;
	for (int i = f, j = 0; i <= n; i ++, j ++)
	{
		mins = min(mins, pre[j]);
		if (pre[i] - mins >= 0)
			return true;
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
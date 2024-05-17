/**
 * @file 管道.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-17
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	使用二分，并且在check函数中O(n)判断是否满足条件
 * 	总时间复杂度为O(nlogn)，数据大小为10^5，不会超时
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
long long l[N], s[N], diff[N];
long long n, len;

bool check(int mid)
{
	// cout << "mid:" << mid << endl;
	memset(diff, 0, sizeof diff);
	// 经过mid时间判断是否都能检测到有水流
	for (int i = 1; i <= n; i ++)
	{
		if (mid >= s[i])
		{
			int a = max((long long)1, l[i] - (mid - s[i]));
			int b = min(len + 1, l[i] + (mid - s[i]) + 1);
			diff[a] ++;
			diff[b] --;
		}
	}
	// for (int i = 1; i <= len; i ++) cout << diff[i] << " ";
	// cout << endl;
	// 遍历区间len
	int tmp = 0;
	for (int i = 1; i <= len; i ++)
	{
		tmp += diff[i];
		if (tmp <= 0) return false;
	}
	return true;
}

int main()
{
	cin >> n >> len;
	for (int i = 1; i <= n; i ++) cin >> l[i] >> s[i];

	int l = 0, r = len;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}

	cout << r;
	return 0;
}
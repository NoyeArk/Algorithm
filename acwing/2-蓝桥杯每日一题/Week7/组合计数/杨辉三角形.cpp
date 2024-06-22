/**
 * @file 杨辉三角形.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-21
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	杨辉三角：左右对称
 * 	从第16行开始枚举
 */

#include <iostream>
using namespace std;

typedef long long LL;

int n;

LL C(int a, int b)
{
	LL res = 1;
	for (int i = a, j = 1; j <= b; i --, j ++)
	{
		res = res * i / j;
		if (res > n) return res;
	}
	return res;
}

bool check(int k)
{
	LL l = k * 2, r = n;
	if (l > r) return false;
	while (l < r)
	{
		LL mid = l + r >> 1;
		if (C(mid, k) >= n) r = mid;
		else l = mid + 1;
	}
	if (C(r, k) != n) return false;

	cout << r * (r + 1) / 2 + k + 1 << endl;
	return true;
}

int main()
{
	cin >> n;

	for (int k = 16; ; k --)
		if (check(k)) break;

	return 0;
}
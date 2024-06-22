/**
 * @file 冶炼金属.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-13
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 10010;
int n;
int A[N], B[N];

bool check1(int mid)
{
	for (int i = 1; i <= n; i ++)
		if (A[i] / mid > B[i]) return false;
	return true;
}

bool check2(int mid)
{
	for (int i = 1; i <= n; i ++)
		if (A[i] / mid < B[i]) return false;
	return true;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> A[i] >> B[i];

	// 找最小值
	int l = 1, r = 1e9;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check1(mid)) r = mid;
		else l = mid + 1;
	}
	cout << r << " ";
	
	l = 1, r = 1e9;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (check2(mid)) l = mid;
		else r = mid - 1;
	}

	cout << r;
	return 0;
}
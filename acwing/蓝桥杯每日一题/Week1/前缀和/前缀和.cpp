/**
 * @file 前缀和.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-02
 * @copyrig	ht Copyright (c) 2024
 * 
 * @brief 
 * 	使用cin和cout：
 * 		运行时间：1035ms	运行空间：2908KB
 * 	使用scanf和printf：
 * 		运行时间：926ms		运行空间：2908KB
 */

#include <iostream>
using namespace std;

const int N = 100010;
int a[N];

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i ++) 
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}

	while (m --)
	{
		int l, r; cin >> l >> r;
		cout << a[r] - a[l - 1] << endl;
	}

	return 0;
}
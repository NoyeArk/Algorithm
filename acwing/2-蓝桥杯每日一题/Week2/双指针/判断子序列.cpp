/**
 * @file 判断子序列.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-02
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int a[N], b[N];

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= m; i ++) cin >> b[i];

	int i, j;
	for (i = 1, j = 1; i <= n && j <= m; j ++)
		if (a[i] == b[j]) i ++;
		
	cout << (i > n ? "Yes" : "No");
	return 0;
}
/**
 * @file 数组元素的目标和.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-26
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
	int n, m, x; cin >> n >> m >> x;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int j = 1; j <= m; j ++) cin >> b[j];

	int i = 1, j = m;
	while (i <= n && j >= 1)
	{
		while (a[i] + b[j] > x) j --;
		while (a[i] + b[j] < x) i ++;
		if (a[i] + b[j] == x) break;
	}
	cout << i - 1 << " " << j - 1;
	return 0;
}
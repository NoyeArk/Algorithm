/**
 * @file 完全背包问题.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-08
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	时间复杂度：O(n²)	空间复杂度：O(n)
 * 	运行时间：46ms	运行空间：220KB
 */

#include <iostream>
using namespace std;

const int N = 1010;
int f[N];

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i ++) 
	{
		int v, w; cin >> v >> w;
		for (int j = v; j <= m; j ++)
			f[j] = max(f[j], f[j - v] + w);
	}

	cout << f[m];
	return 0;
}
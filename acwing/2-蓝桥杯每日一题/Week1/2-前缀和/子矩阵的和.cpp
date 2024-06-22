/**
 * @file 子矩阵的和.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-07
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	运行时间：5678ms	运行空间：5716KB
 */

#include <iostream>
using namespace std;

const int N = 1010;
int pre[N][N];

int main()
{
	int n, m, q; cin >> n >> m >> q;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
		{
			int x; cin >> x;
			pre[i][j] = x + pre[i][j - 1];
		}

	while (q --)
	{
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int ans = 0;
		for (int i = x1; i <= x2; i ++)
			ans += pre[i][y2] - pre[i][y1 - 1];
		cout << ans << endl;
	}

	return 0;
}
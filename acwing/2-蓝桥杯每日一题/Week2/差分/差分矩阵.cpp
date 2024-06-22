/**
 * @file 差分矩阵.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-31
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	区间操作考虑用差分，可以实现对区间的快速更新
 */

#include <iostream>
using namespace std;

const int N = 1010;
int a[N][N], diff[N][N];

int main()
{	
	int n, m, q; cin >> n >> m >> q;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
		{
			cin >> a[i][j];
			diff[i][j] = a[i][j] - a[i][j - 1];
		}

	while (q --)
	{
		int x1, y1, x2, y2, c; cin >> x1 >> y1 >> x2 >> y2 >> c;
		for (int i = x1; i <= x2; i ++)
			diff[i][y1] += c, diff[i][y2 + 1] -= c;
	}

	for (int i = 1; i <= n; i ++)
	{
		int tmp = 0;
		for (int j = 1; j <= m; j ++)
		{
			tmp += diff[i][j];
			cout << tmp << " ";
		}
		cout << endl;
	}

	return 0;
}
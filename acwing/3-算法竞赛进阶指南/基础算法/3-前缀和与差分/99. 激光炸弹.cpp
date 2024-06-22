/**
 * @file 99. 激光炸弹.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-22
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

const int N = 5010;
int g[N][N], col[N][N];

int main()
{
	int n, R; cin >> n >> R;
	for (int i = 1; i <= n; i ++)
	{
		int x, y, w; cin >> x >> y >> w;
		g[x + 1][y + 1] = w;
	}

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			g[i][j] += g[i][j - 1], col[i][j] = col[i - 1][j] + g[i][j];

	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= n; j ++)
			cout << g[i][j] << " ";
		cout << endl;
	}

	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= n; j ++)
			cout << col[i][j] << " ";
		cout << endl;
	}

	int ans = 0;

	if (R >= 5000) 
	{
		for (int i = 1; i <= n; i ++)
			ans += g[i][n];
		cout << ans;
		return 0;
	}

	for (int i = 1; i <= n - R + 1; i ++)
		for (int j = 1; j <= n - R + 1; j ++)
		{
			if (R == 1) 
			{
				ans = max(ans, )
			}
			int x1 = i, x2 = i + R - 1, y1 = j, y2 = j + R - 1;

			ans = max(ans, col[x2][y2] - col[x2][y1] - col[x1][y2] + col[x1][y1]);
		}

	cout << ans;
	return 0;
}
/**
 * @file 99. 激光炸弹.cpp
 * @author horiki
 * @version 0.2
 * @date 2024-06-22 2024-07-19
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 5001, M = 5010;
int g[M][M];

int main()
{
	int n, R; cin >> n >> R;
	while (n --)
	{
		int x, y, w; cin >> x >> y >> w;
		g[x + 1][y + 1] += w;
	}

	for (int i = 1; i <= N; i ++)
		for (int j = 1; j <= N; j ++)
			g[i][j] += g[i][j - 1] + g[i - 1][j] - g[i - 1][j - 1];

	int ans = 0;
	R = min(N, R);

	for (int i = R; i <= N; i ++)
		for (int j = R; j <= N; j ++)
			ans = max(ans, g[i][j] - g[i - R][j] - g[i][j - R] + g[i - R][j - R]);

	cout << ans;
	return 0;
}
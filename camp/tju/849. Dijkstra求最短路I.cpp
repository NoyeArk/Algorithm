/**
 * @file 849. Dijkstra求最短路I.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-07-01
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;
int n, m;
int g[N][N], dist[N];
bool st[N];

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for (int i = 1; i <= n; i ++)
	{
		int t = -1;
		for (int j = 1; j <= n; j ++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		st[t] = true;
		for (int j = 1; j <= n; j ++)
			dist[j] = min(dist[j], dist[t] + g[t][j]);
	}
	return dist[n] > 0x3f3f3f3f / 2 ? -1 : dist[n];
}

int main()
{
	memset(g, 0x3f, sizeof g);
	cin >> n >> m;
	while (m --)
	{
		int a, b, c; cin >> a >> b >> c;
		g[a][b] = min(g[a][b], c);
	}

	cout << dijkstra();
	return 0;
}
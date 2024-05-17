/**
 * @file spfa求最短路.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-17
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	1.正权单源最短路
 * 		1.1 dijkstra O(n²)
 * 		1.2 堆优化的dijkstra O(nlogn)
 * 	2.负权单源最短路
 * 		2.1 bellman_ford O(nm)
 * 		2.2 spfa O(nm)，通常为O(m)
 * 	3.多源最短路 
 * 		3.1 弗洛伊德算法 O(n³)
 */

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];

void spfa()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;

	// 进行松弛操作
	queue<int> q;
	q.push(1);
	st[1] = true;

	while (q.size())
	{
		auto t = q.front(); q.pop();
		st[t] = false;
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if (!st[j]) 
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while (m --)
	{
		int a, b, c; cin >> a >> b >> c;
		e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
	}

	spfa();
	cout << (dist[n] > 0x3f3f3f3f / 2 ? "impossible" : to_string(dist[n]));
	return 0;
}
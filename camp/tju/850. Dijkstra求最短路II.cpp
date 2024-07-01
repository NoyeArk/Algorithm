/**
 * @file 850. Dijkstra求最短路II.cpp
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
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> PII;

const int N = 150010;
int n, m;
int h[N], e[N], ne[N], w[N], idx;

int dist[N];
bool st[N];

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, 1});
	while (heap.size())
	{
		auto t = heap.top(); heap.pop();
		int ver = t.second;

		if (st[ver]) continue;
		st[ver] = true;

		for (int i = h[ver]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[ver] + w[i])
			{
				dist[j] = dist[ver] + w[i];
				heap.push({dist[j], j});
			}
		}
	}
	return dist[n] > 0x3f3f3f3f / 2 ? -1 : dist[n];
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while (m --)
	{
		int x, y, z; cin >> x >> y >> z;
		e[idx] = y, ne[idx] = h[x], w[idx] = z, h[x] = idx ++;
	}
	cout << dijkstra();
	return 0;
}
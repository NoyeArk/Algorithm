/**
 * @file 850. Dijkstra求最短路 II .cpp
 * @author horiki
 * @version 0.1
 * @date 2024-07-12
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;

const int N = 150010;
int n, m;
bool st[N];
int dist[N];
int h[N], e[N], ne[N], w[N], idx;

bool dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, 1});
	while (heap.size())
	{
		int ver = heap.top().second; heap.pop();
		if (st[ver]) continue;
		st[ver] = true;
		for (int i = h[ver]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[ver] + w[i])
				dist[j] = dist[ver] + w[i], heap.push({dist[j], j});
		}
	}
	return dist[n] != 0x3f3f3f3f;
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
	cout << (dijkstra() ? dist[n] : -1);
	return 0;
}
/**
 * @file 850. Dijkstra求最短路 II 3.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-03
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;

typedef pair<int, int> PII;

const int N = 150010;
int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];

void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, 1});
	while (heap.size())
	{
		int t = heap.top().second; heap.pop();
		if (st[t]) continue;
		st[t] = true;
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])
				dist[j] = dist[t] + w[i], heap.push({dist[j], j});
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

	dijkstra();
	if (dist[n] > 0x3f3f3f3f / 2) cout << -1;
	else cout << dist[n];

	return 0;
}
/**
 * @file Dijkstra求最短路II.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-16
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

const int N = 200010;
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
        // 选出距离最近的点
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
}   

int main()
{
	cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m --)
    {
        int a, b, c; cin >> a >> b >> c;
        e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
    }
	dijkstra();
	if (dist[n] == 0x3f3f3f3f) cout << -1;
	else cout << dist[n];
	return 0;
}
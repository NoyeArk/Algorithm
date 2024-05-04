/**
 * @file Dijkstra求最短路II.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-04
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  可能是稀疏图，使用邻接表存储，使用堆优化，O(nlogn)
 */

#include <iostream>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 200010;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
int n, m;
bool st[N];

int dijkstra()
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
    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
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
    cout << dijkstra();
    return 0;
}
/**
 * @file spfa求最短路.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-07
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  1.适用范围：
 *   给定的图存在负权边，这时类似Dijkstra等算法便没有了用武之地，而Bellman-Ford算法的复杂度又过高，SPFA算法便派上用场了。
 *  2.算法思想：
 *   我们用数组d记录每个结点的最短路径估计值，用邻接表来存储图G。
 *   我们采取的方法是动态逼近法：
 *   设立一个先进先出的队列用来保存待优化的结点，优化时每次取出队首结点u，
 *   并且用u点当前的最短路径估计值对离开u点所指向的结点v进行松弛操作，
 *   如果v点的最短路径估计值有所调整，且v点不在当前的队列中，就将v点放入队尾。
 *   这样不断从队列中取出结点来进行松弛操作，直至队列空为止
 *  3.判断有无负环：
 *   如果某个点进入队列的次数超过V次则存在负环（SPFA无法处理带负环的图）。
 */

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 100010;
int h[N], ne[N], e[N], w[N], idx;
int n, m;
int dist[N];
bool st[N];

void spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q; q.push(1);
    st[1] = true;

    while (q.size())
    {
        int t = q.front(); q.pop();
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
    if (dist[n] > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << dist[n];
    return 0;
}
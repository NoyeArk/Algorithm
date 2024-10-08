/**
 * @file 851. spfa求最短路 5.cpp
 * @author horiki
 * @date 2024-09-12
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010;
int n, m;
int h[N], ne[N], e[N], w[N], idx;
int dist[N];
bool st[N];  // 标志是否在队列中

void spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
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
                if (!st[j]) q.push(j), st[j] = true;
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
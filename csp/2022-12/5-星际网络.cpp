/**
 * @file 5-星际网络.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-13
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

// typedef pair<int, int> PII;

const int N = 100010, P = 1e9 + 7;
int n, m;
int w[N];
set<int> g[N];

int dist[N];
bool st[N];

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 1; i < n; i ++)
    {
        int t = -1;
        for (int j = 1; j <= n; j ++)   
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        st[t] = true;
        for (auto j : g[t])
        {
            dist[j] = min(dist[j], dist[t] + w[j]);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        int l1, r1, l2, r2, a, b;
        cin >> l1 >> r1 >> l2 >> r2 >> a >> b;
        // [l1, r1]到结点i为一条有向边
        for (int j = l1; j <= r1; j ++)
            if (j == i) continue;
            else g[j].insert(i);
        // 结点i到[l2, r2]为一条有向边
        for (int j = l2; j <= r2; j ++)
            if (j == i) continue;
            else g[i].insert(j);
        w[i] = a * (1 << b);
    }
    for (int i = 1; i <= n; i ++) cout << w[i] << " " ;
    cout << endl;
    for (int i = 1; i <= n; i ++)
    {
        for (auto t : g[i])
            cout << t << " ";
        cout << endl;
    }
        
    dijkstra();
    for (int i = 2; i <= n; i ++) cout << dist[i] << " ";
    return 0;
}
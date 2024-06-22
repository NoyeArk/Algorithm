/**
 * @file Prim算法求最小生成树.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-09
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  每次选择一个距当前集合最近的结点进行加入
 *  什么时候最小生成树不存在？
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;
int n, m;
int g[N][N], dist[N];
bool st[N];  // 标志是否已经加入生成树

int prim()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    int res = 0;
    // 遍历n次，每次选择一个结点加入生成树
    for (int i = 1; i <= n; i ++)
    {
        int t = -1;
        for (int j = 1; j <= n; j ++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        // 加入生成树
        st[t] = true;
        res += dist[t];
        if (res > 0x3f3f3f3f / 2) return 0x3f3f3f3f;
        // 更新其他到生成树的距离
        for (int j = 1; j <= n; j ++)
            dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main()
{
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    while (m --)
    {
        int a, b, c; cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    int res = prim();
    if (res > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << res;
    return 0;
}
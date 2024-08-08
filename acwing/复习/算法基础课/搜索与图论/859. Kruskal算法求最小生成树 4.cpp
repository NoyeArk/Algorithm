/**
 * @file 859. Kruskal算法求最小生成树 4.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-08
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010, M = 200010;
int n, m;
int pre[N];
struct Edge
{
    int a, b, c;
}edges[M];

bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
}

int find(int x)
{
    return pre[x] = (pre[x] == x ? x : find(pre[x]));
}

int kruskal()
{
    int res = 0, cnt = 0;
    for (int i = 1; i <= m; i ++)
    {
        auto e = edges[i];
        int a = find(e.a), b = find(e.b);
        if (a != b) pre[a] = b, res += e.c, cnt ++;
    }
    return cnt < n - 1 ? 0x3f3f3f3f : res;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) pre[i] = i;

    for (int i = 1; i <= m; i ++)
    {
        int a, b, c; cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }

    sort(edges + 1, edges + 1 + m, cmp);

    int ans = kruskal();
    if (ans > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << ans;

    return 0;
}
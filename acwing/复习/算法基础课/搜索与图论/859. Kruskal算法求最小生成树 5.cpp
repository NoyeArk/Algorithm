/**
 * @file 859. Kruskal算法求最小生成树 5.cpp
 * @author horiki
 * @date 2024-09-12
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010, M = 200010;
int n, m;
int pre[N];
struct Edge
{
    int a, b, c;
}edges[M];

int find(int x)
{
    return pre[x] = (pre[x] == x ? x : find(pre[x]));
}

bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
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
    return cnt == n - 1 ? res : 0x3f3f3f3f;
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
    int res = kruskal();
    if (res == 0x3f3f3f3f) cout << "impossible";
    else cout << res;
    return 0;
}
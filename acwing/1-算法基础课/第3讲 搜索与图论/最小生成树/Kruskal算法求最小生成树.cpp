/**
 * @file Kruskal算法求最小生成树.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-24
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * Kruskal算法：
 *  1、将所有边按权重从小到达排序 O(mlogm)
 *  2、枚举每一条边a->b 权重为c  O(m)
 *      if a b 不连通
 *          将a->b加入集合中
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200010;
int pre[N];
int n, m; 

struct Edge
{
    int a, b, w;
}edges[N];

bool cmp(Edge& a, Edge& b)
{
    // 不能加等于
    return a.w < b.w;
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
        
        if (a != b)
        {
            pre[a] = b;
            res += e.w; cnt ++;
        }
    }
    return cnt < n - 1 ? 0x3f3f3f3f : res;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) pre[i] = i;
    
    for (int i = 1; i <= m; i ++) 
    {
        int u, v, w; cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    
    sort(edges + 1, edges + m + 1, cmp);
    
    int ans = kruskal();
    
    if (ans == 0x3f3f3f3f) cout << "impossible";
    else cout << ans;
    return 0;
}
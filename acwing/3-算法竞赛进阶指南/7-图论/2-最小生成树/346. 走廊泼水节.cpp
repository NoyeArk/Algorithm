/**
 * @file 346. 走廊泼水节.cpp
 * @author horiki
 * @date 2024-08-17
 * 
 * @brief 
 *  完全图的定义应该是每2个结点之间都有边相连吧？
 *  能不能把这道题转化一下，往你会的知识点上靠，怎么转化成最小生成树？
 *  要求增加完新边之后最小生成树还是原来的，能不能反着想？
 *  就是一开始没有赋值的边是无穷大，好像不行
 *  含有n个结点的完全图的边个数为 n - 1 + n - 2 + .. + 2 + 1 = n(n - 1)/2
 *  含有n个结点的最小生成树的边个数为n - 1
 *  实在不知道怎么做....
 *  ——————————————————————————————————————————
 *  正确做法：
 *      在执行kruskal算法的过程中，记录每个连通块的结点个数，然后将剩下的边乘w+1
 *  ——————————————————————————————————————————
 *  为什么自己想不出来？
 *      感觉这道题最关键的地方就是理解连通块这个概念，每次将2个连通块结合起来
 *      在结合的过程中计算答案
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 20010;
int cnt[N], pre[N];

struct Edge
{
    int a, b, c;
}edges[N];

bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
}

int find(int x)
{
    return pre[x] = pre[x] == x ? x : find(pre[x]);
}

void kruskal()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) pre[i] = i, cnt[i] = 1;

    for (int i = 1; i < n; i ++)
    {
        int a, b, c; cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }

    sort(edges + 1, edges + n, cmp);

    int ans = 0;
    for (int i = 1; i < n; i ++)
    {
        auto e = edges[i];
        int a = find(e.a), b = find(e.b);
        if (a != b)
        {
            ans += (cnt[a] * cnt[b] - 1) * (e.c + 1);
            pre[a] = b;
            cnt[b] += cnt[a];
        }
    }
    cout << ans << endl;
}

int main()
{
    int t; cin >> t;
    while (t --) kruskal();
    return 0;
}
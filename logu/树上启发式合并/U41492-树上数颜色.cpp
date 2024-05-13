/**
 * @file U41492-树上数颜色.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-13
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  https://www.luogu.com/article/6028aw8w
 *  https://www.luogu.com.cn/problem/U41492#submit
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100010;
int h[N], e[N], ne[N], idx;
int sz[N], son[N], cnt[N], c[N], ans[N], sum;
bool vis[N];

// 找每个结点的重结点
void dfs(int u, int f)
{
    sz[u] = 1;  // 结点u的子树中所含有的结点个数
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        dfs(j, u);
        sz[u] += sz[j];
        if (sz[j] > sz[son[u]])
            son[u] = j;
    }
}

void cal(int u, int f, int k)
{
    if (k > 0) 
    {
        if (!cnt[c[u]]) sum ++;
        cnt[c[u]] ++;
    }
    else
    {
        if (cnt[c[u]]) sum --;
        cnt[c[u]] --;
    }
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (vis[j]) continue;
        cal(j, u, k);
    }
}

void dsu(int u, int f, int keep)
{
    // 遍历所有的轻儿子，递归结束时消除它们的贡献
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        // 避开重儿子
        if (j == son[u]) continue;
        dsu(j, u, 0);  // 不计算轻儿子的贡献
    }
    // 遍历所有的重儿子，保留它的贡献
    if (son[u]) dsu(son[u], u, 1), vis[son[u]] = true;
    // 再计算当前子树中所有轻子树的贡献
    cal(u, f, 1), vis[son[u]] = false;
    // 更新答案
    ans[u] = sum;
    // 如果是轻结点，不计入贡献
    if (!keep) cal(u, f, -1);
}

int main()
{
    memset(h, -1, sizeof h);
    int n; cin >> n;
    for (int i = 1; i < n; i ++)
    {
        int a, b; cin >> a >> b;
        e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
    }
    for (int i = 1; i <= n; i ++) cin >> c[i];

    dfs(1, 0);
    dsu(1, 0, 1);

    int m; cin >> m;
    while (m --)
    {
        int x; cin >> x;
        cout << ans[x] << endl;
    }
    return 0;
}
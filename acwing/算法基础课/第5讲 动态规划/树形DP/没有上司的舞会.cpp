/**
 * @file 没有上司的舞会.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-13
 * @copyright Copyright (c) 2024
 * 
 * @brief
 *  树形DP：从根节点开始递归求解
 *  1.状态表示：
 *      1.1 f[u][0]表示从以u为根的子树中选择，并且不选u这个点的方案
 *      1.2 f[u][1]表示从以u为根的子树中选择，并且  选u这个点的方案
 *  2.状态计算：
 *      2.1 f[u][0] += max(f[si][0], f[s1][1])
 *      2.2 f[u][1] += max(f[si][0])
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 6010;
int h[N], e[N], ne[N], idx;
int a[N];
int f[N][2];

bool d[N];

void dfs(int u)
{
    f[u][1] = a[u];

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        dfs(j);

        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}

int main()
{
    memset(h, -1, sizeof h);
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i < n; i ++)
    {
        int l, k; cin >> l >> k;
        e[idx] = l, ne[idx] = h[k], h[k] = idx ++;
        d[l] = true;
    }

    int r = 1;
    while (d[r]) r ++;

    dfs(r);

    cout << max(f[r][0], f[r][1]);
    return 0;
}
/**
 * @file 染色法判定二分图.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-24
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  性质：一个图是二分图当且仅当图中不含奇数环
 *  二分图：把所有点划分为两个集合，每个集合内部没有边相连
 *  如果用染色法染色的过程中出现了矛盾，就不是二分图
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010, M = 200010;
int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool dfs(int u, int c)
{
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!color[j])
        {
            if (!dfs(j, 3 - c)) return false;
        }
        else if (color[j] == c) return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);

    while (m --)
    {
        int a, b; cin >> a >> b;
        add(a, b); add(b, a);
    }

    bool flag = true;
    for (int i = 1; i <= n; i ++)
    {
        if (!color[i])
        {
            if (!dfs(i, 1))
            {
                flag = false;
                break;
            }
        }
    }

    if (flag) cout << "Yes";
    else cout << "No";

    return 0;
}
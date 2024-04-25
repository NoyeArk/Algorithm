/**
 * @file 二分图的最大匹配.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-25
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  匈牙利算法：不存在两条边公用一个点
 *      时间复杂度：O(n*m)
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 100010;
int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[M];
bool st[N];

bool find(int x)
{
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            st[j] = true;
            if (match[j] == 0 || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof h);

    while (m --)
    {
        int a, b; cin >> a >> b;
        e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
    }

    int res = 0;  // 当前匹配的数量
    for (int i = 1; i <= n1; i ++)
    {
        memset(st, false, sizeof st);
        if (find(i)) res ++;
    }

    cout << res;
    return 0;
}
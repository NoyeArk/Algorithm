/**
 * @file 食物链.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-08
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  1.记录一下每个点和根节点之间的关系
 *  2.每个点到根节点的距离表示这个关系，距离分为3类：
 *      余1：可以吃根节点
 *      余2：可以被根节点吃
 *      余0：和根节点是同类
 */

#include <iostream>
using namespace std;

const int N = 50010;
int n, m;
int pre[N], d[N];

int find(int x)
{
    if (pre[x] != x) 
    {
        int t = find(pre[x]);
        d[x] += d[pre[x]];
        pre[x] = t;
    }
    return pre[x];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) pre[i] = i;

    int res = 0;
    while (m --)
    {
        int t, x, y; cin >> t >> x >> y;
        if (x > n || y > n) res ++;
        else
        {
            int px = find(x), py = find(y);
            if (t == 1)
            {
                if (px == py && (d[x] - d[y]) % 3) res ++;
                else if (px != py)
                {
                    pre[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else if (t == 2)
            {
                if (px == py && (d[x] - d[y] - 1) % 3) res ++;
                else if (px != py)
                {
                    pre[px] = py;
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    cout << res;
    return 0;
}
/**
 * @file 多重背包问题 II.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-24
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  使用多重背包的二进制优化方法
 *  如何把多重背包问题变成01背包问题
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2010;

int n, m;
int f[N];

struct Good
{
    int v, w;
};

int main()
{
    vector<Good> goods;
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
    {
        int v, w, s; cin >> v >> w >> s;
        for (int k = 1; k <= s; k *= 2)
        {
            s -= k;
            goods.push_back({v * k, w * k});
        }
        if (s >= 0) goods.push_back({v * s, w * s});
    }

    for (auto it : goods)
        for (int j = m; j >= it.v; j --)
            f[j] = max(f[j], f[j - it.v] + it.w);

    cout << f[m] << endl;
    return 0;
}
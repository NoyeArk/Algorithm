/**
 * @file 2. 01背包问题.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-13
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  状态表示：f[i][j]表示在选第i个物品，背包容量不超过j的情况下的最大价值
 *  状态计算：
 *      不选第i个物品：f[i][j] = f[i - 1][j]
 *      选择第i个物品：
 *          f[i][j] = f[i - 1][j - v[i]] + w[i]
 */

#include <iostream>
using namespace std;

const int N = 1010;
int v[N], w[N], f[N][N];

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= m; j ++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }

    cout << f[n][m];
    return 0;
}
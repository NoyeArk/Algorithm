/**
 * @file 多重背包问题I.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-01
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  多重背包问题，每件物品最多有si件。
 *      1.不选第i件物品：f[i][j] = f[i - 1][j]
 *      2.选第i件物品，选多少件？
 *          选1件：f[i][j] = f[i - 1][j - v[i]] + w[i]
 *          选2件：f[i][j] = f[i - 1][j - 2 * v[i]] + 2 * w[i]
 *          选3件：f[i][j] = f[i - 1][j - 3 * v[i]] + 3 * w[i]
 *          …………         
 *          选si件：f[i][j] = f[i - 1][j - si * v[i]] + si * w[i]
 *          f[i][j] = max(选1件, 选2件, …………, 选si件)
 *          令j = j - v[i], 则f[i][j - v[i]] = max((f[i - 1][j - 2 * v[i]] + w[i]), (f[i - 1][j - 3 * v[i]] + 2 * w[i]), …………)
 *          f[i][j] = f[i][j - v[i]] + w[i]
 *      3.得到状态转移方程：
 *          f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i])
 */

#include <iostream>
using namespace std;

const int N = 110;
int v[N], w[N], s[N];
int f[N][N];

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> v[i] >> w[i] >> s[i];

    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j <= m; j ++ )
            for (int k = 0; k <= s[i] && k * v[i] <= j; k ++ )
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);

    cout << f[n][m];
    return 0;
}
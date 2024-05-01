/**
 * @file 完全背包问题.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-01
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  完全背包问题：
 *      1.不选第i件物品：f[i][j] = f[i - 1][j]
 *      2.选第i件物品，选多少件？
 *          选1件：f[i][j] = f[i - 1][j - v[i]] + w[i]
 *          选2件：f[i][j] = f[i - 1][j - 2 * v[i]] + 2 * w[i]
 *          选3件：f[i][j] = f[i - 1][j - 3 * v[i]] + 3 * w[i]
 *          …………         
 *          选n件：f[i][j] = f[i - 1][j - n * v[i]] + n * w[i]
 *          f[i][j] = max(选1件, 选2件, …………, 选n件)
 *          令j = j - v[i], f[i][j] = f[i][j - v[i]] + w[i]
 *      3.得到状态转移方程：
 *          f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i])
 */

#include <iostream>
using namespace std;

const int N = 1010;
int v[N], w[N];
int f[N][N];

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
        }

    cout << f[n][m];
    return 0;
}

// *******************优化版*******************
// #include <iostream>
// using namespace std;

// const int N = 1010;
// int v[N], w[N];
// int f[N];

// int main()
// {
//     int n, m; cin >> n >> m;
//     for (int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

//     for (int i = 1; i <= n; i ++)
//         for (int j = m; j >= v[i]; j --)
//         {
//             f[j] = max(f[j], f[j - v[i]] + w[i]);
//         }

//     cout << f[m];
//     return 0;
// }
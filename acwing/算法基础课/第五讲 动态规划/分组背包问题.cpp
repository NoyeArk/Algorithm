/**
 * @file 分组背包问题.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-01
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  f[i][j]表示选到第i组时剩余容量j的最大价值
 *      1.不选第i组：f[i][j] = f[i - 1][j]
 *      2.选第i组，第i组中有s个物品，判断选哪个可以价值最大
 *          选第1个：f[i][j] = f[i - 1][j - v[1]] + w[1]
 *          选第2个：f[i][j] = f[i - 1][j - v[2]] + w[2]
 *          ……………
 *          选第s个：f[i][j] = f[i - 1][j - v[s]] + w[s]
 *        f[i][j] = max(选第1个, 选第2个, …………, 选第s个)
 */

#include <iostream>
using namespace std;

const int N = 110;
int s[N], v[N][N], w[N][N];
int f[N][N];

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        cin >> s[i];
        for (int j = 1; j <= s[i]; j ++) cin >> v[i][j] >> w[i][j];
    }

    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= m; j ++)
        {
            f[i][j] = f[i - 1][j];
            for (int k = 1; k <= s[i]; k ++)
            {
                if (j >= v[i][k])
                    f[i][j] = max(f[i][j], f[i - 1][j - v[i][k]] + w[i][k]);
            }
        }

    cout << f[n][m];
    return 0;
}
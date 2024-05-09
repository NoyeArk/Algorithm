/**
 * @file 石子合并.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-09
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  区间DP一般枚举区间长度，当区间长度为1时没有必要枚举
 *  1.状态表示
 *      1.1 集合：f[i][j]表示合并[i, j]
 *      1.2 属性：将区间[i, j]内的石子合并需要的最小代价
 *  2.状态计算
 *      一共有3种：
 *      2.1 f[i][j] = a[i] + f[i + 1][j]
 *      2.2 f[i][j] = f[i][j - 1] + a[j]
 *      2.3 f[i][j] = f[i][k - 1] + a[k] + f[k + 1][j]
 */

#include <iostream>
using namespace std;

const int N = 310;
int a[N], f[N][N];

int main()
{   
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i], a[i] += a[i - 1];

    for (int len = 2; len <= n; len ++)
        for (int i = 1; i + len - 1 <= n; i ++)
        {
            int j = i + len - 1;
            f[i][j] = 1e8;
            for (int k = i; k < j; k ++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + a[j] - a[i - 1]);
        }

    // for (int i = 1; i <= n; i ++)
    //     for (int j = 1; j <= n; j ++)
    //     {
    //         f[i][j] = 1e8;
    //         for (int k = i; k < j; k ++)
    //         {
    //             f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + a[j] - a[i - 1]);
    //             printf("i:%d k:%d j:%d f[i][j]:%d\n", i, k, j, f[i][j]);
    //         }
    //     }
    cout << f[1][n];
    return 0;
}
/**
 * @file 最短Hamilton路径.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-15
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  旅行商问题，NP完全问题
 *  1.哪些点被用过
 *  2.目前停在哪个点上
 *  f[i][j]表示i个点被用过，j表示目前停在j上
 */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20, M = 1 << 20;

int n;
int f[M][N], weight[N][N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            cin >> weight[i][j];

    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;

    // 遍历所有的状态
    for (int i = 0; i < 1 << n; i ++)
        // 最后停在点j上
        for (int j = 0; j < n; j ++)
            if (i >> j & 1)
                for (int k = 0; k < n; k ++)
                    if (i - (1 << j) >> k & 1)
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + weight[k][j]);

    cout << f[(1 << n) - 1][n - 1];
    return 0;
}
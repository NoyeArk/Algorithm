/**
 * @file 数字三角形.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-02
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  从上到下分析：需要额外加判断
 *      状态表示：f[i][j]表示走到第i层第j个位置的最大和
 *      f[i][j]从f[i - 1][j - 1]或f[i - 1][j]转移过来
 *      f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j]
 *  从下到上分析：
 *      1.状态表示：从经验得出
 *          1.1 集合：从底向上走到[i, j]的所有路线的集合
 *          1.2 属性：一般只有三类，最大值、最小值和个数
 *      2.状态计算
 *          从左下角过来、从右下角过来
 */

// 从下到上
#include <iostream>
using namespace std;

const int N = 510;
int a[N][N], f[N][N];

int main()
{
    int n; cin >> n;

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= i; j ++)
            cin >> a[i][j];

    f[1][1] = a[1][1];
    for (int i = 2; i <= n; i ++)
        for (int j = 1; j <= i; j ++)
            if (j == 1) f[i][1] = f[i - 1][1] + a[i][j];
            else if (j == i) f[i][j] = f[i - 1][j - 1] + a[i][j];
            else f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];

    int ans = f[n][1];
    for (int i = 1; i <= n; i ++)
        ans = max(ans, f[n][i]);

    cout << ans;
    return 0;
}
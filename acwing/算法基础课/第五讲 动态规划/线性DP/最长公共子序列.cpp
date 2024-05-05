/**
 * @file 最长公共子序列.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-05
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  1.状态表示
 *      f[i][j]表示公共串是中以串A中下标i结尾、串B中以下标j结尾的最大串长
 *  2.状态计算
 *      2.1 朴素做法：两层循环遍历，O(n²)，不会超时
 *          如果a[i] != b[j]，f[i][j] = max(f[i - 1][j], f[i][j - 1])
 *          如果a[i] == b[j]，f[i][j] = max(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1] + 1)
 */

#include <iostream>
using namespace std;

const int N = 1010;
char a[N], b[N];
int f[N][N];

int main()
{
    int n, m; cin >> n >> m >> a + 1 >> b + 1;

    for (int i = 1; i <= n; i ++)
    {
        f[i][0] = f[i - 1][1];
        for (int j = 1; j <= m; j ++)
        {
            f[i][j] = max(f[i][j - 1], f[i - 1][j]);
            if (a[i] == b[j])
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    }

    cout << f[n][m];
    return 0;
}
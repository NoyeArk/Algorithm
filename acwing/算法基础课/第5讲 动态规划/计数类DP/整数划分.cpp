/**
 * @file 整数划分.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-10
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  1.状态表示  
 *      f[i]表示数字i有多少种不同的划分方法
 *  2.状态计算
 *      f[i] = f[i - 1] + 1
 *      if i % 2 == 0:
 *          f[i] += 1
 * -----------------------------------------
 *  看成完全背包问题
 *  1.状态表示：从1~n选，体积恰好为j
 *  2.状态计算
 *      f[j] = f[i - 1][j] + f[i][j - i]
 */

#include <iostream>
using namespace std;

const int N = 1010, P = 1e9 + 7;
int n;
int f[N];

int main()
{
    cin >> n;

    f[0] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = i; j <= n; j ++)   
            f[j] = (f[j] + f[j - i]) % P;

    cout << f[n];
    return 0;
}
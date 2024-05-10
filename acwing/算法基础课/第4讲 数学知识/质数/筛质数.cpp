/**
 * @file 筛质数.cpp
 * @author horiki
 * @version 0.2
 * @date 2024-04-29 2024-05-10
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  线性筛法：每一个数只会被最小质因子筛掉
 *      1. i % primes[j] == 0:
 *          pj一定是i的最小质因子，pj一定是pj*i的最小质因子
 *      2. i % primes[j] == 0:
 *          pj一定小于i的所有质因子，pj也一定是pj*i的最小质因子
 */

#include <iostream>
using namespace std;

const int N = 1000010;
bool st[N];

int main()
{
    int n; cin >> n;
    int ans = 0;
    for (int i = 2; i <= n; i ++)
    {
        if (!st[i]) ans ++;
        for (int j = i + i; j <= n; j += i)
            st[j] = true;
    }
    cout << ans;
    return 0;
}
/**
 * @file 1-最长上升子序列.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-15
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  1.状态表示：f[i]表示以i为结尾的最长递增系序列
 *  2.状态计算：
 */

#include <iostream>
using namespace std;

int a[] = {7,7,7,7,7};

int f[10];

int main() 
{
    int n = 4;
    for (int i = 0; i <= n; i ++) f[i] = 1;

    int ans = 0;
    for (int i = 0; i <= n; i ++)
    {
        for (int j = 0; j < i; j ++)
        {
            if (a[i] > a[j]) 
                f[i] = max(f[i], f[j] + 1);
        }
    }
    
    cout << f[n];
}
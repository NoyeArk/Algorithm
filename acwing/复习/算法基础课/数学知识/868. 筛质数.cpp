/**
 * @file 868. 筛质数.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
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
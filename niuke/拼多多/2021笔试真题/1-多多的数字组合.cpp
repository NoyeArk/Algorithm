/**
 * @file 1-多多的数字组合.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-07
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;

// 最大为9 8 7 6 5 4 3 2 1 0 45
// 时间复杂度：O(n)

bool judge(int x)
{
    int cnt[10];
    memset(cnt, 0, sizeof cnt);
    while (x)
    {
        if (cnt[x % 10] ++ >= 2) return false;
        x /= 10;
    }
    return true;
}

int main() {
    int n; cin >> n;
    if (n > 45) 
    {
        cout << -1;
        return 0;
    }
    for (LL i = 1; i <= 9876543210; i ++)
    {
        if (!judge(i)) continue;
        LL x = i, sum = 0;
        while (x)
        {
            sum += x % 10;
            x /= 10;
        }
        if (sum == n) 
        {
            cout << i; return 0;
        }
    }
    return 0;
}
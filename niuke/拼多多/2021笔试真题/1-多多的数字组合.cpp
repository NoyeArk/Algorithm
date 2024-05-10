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

const int key[] = {9, 17, 24, 30, 35, 39, 42, 44, 45};
const int value[] = {0, 10, 189, 1789, 16789, 156789, 1456789, 13456789, 123456789};

bool judge(int x)
{
    int cnt[10];
    memset(cnt, 0, sizeof cnt);
    while (x)
    {
        if (++ cnt[x % 10] >= 2) return false;
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

    int k = -1;
    for (int i = 0; i < 9; i ++)
        if (n <= key[i])
        {
            k = i;
            break;
        }

    for (LL i = value[k]; i <= 9876543210; i ++)
    {
        if (!judge(i)) continue;
        LL x = i, sum = 0;
        while (x)
        {
            sum += x % 10;
            x /= 10;
        }
        // printf("i:%d sum:%d x:%d\n", i, sum, x);
        if (sum == n) 
        {
            cout << i; return 0;
        }
    }
    return 0;
}
/**
 * @file 约数个数.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-01
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  所有数的乘积的个数，不就相当于每个数的约数的乘积吗
 *  约数个数：
 */

#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long LL;

const int P = 1e9 + 7;

int main()
{
    int n; cin >> n;

    unordered_map<int, int> hash;
    while (n --)
    {
        int x; cin >> x;
        for (int i = 2; i <= x / i; i ++)
        {
            while (x % i == 0)
            {
                x /= i;
                hash[i] ++;
            }
        }
        if (x > 1) hash[x] ++;
    }

    LL ans = 1;
    for (auto t : hash) ans = ans * (t.second + 1) % P;

    cout << ans;
    return 0;
}
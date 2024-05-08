/**
 * @file 约数之和.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-02
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;

int main()
{
    int n; cin >> n;

    unordered_map<int, int> primes;
    while (n --)
    {
        int x; cin >> x;
        for (int i = 2; i <= x / i; i ++)
            while (x % i == 0)
            {
                x /= i;
                primes[i] ++;
            }
        if (x > 1) primes[x] ++;
    }

    LL ans = 1;
    for (auto prime : primes)
    {
        int p = prime.first, a = prime.second;
        LL t = 1;
        while (a --) t = (t * p + 1) % mod;
        ans = ans * t % mod;
    }

    cout << ans;
    return 0;
}
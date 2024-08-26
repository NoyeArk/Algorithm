/**
 * @file 870. 约数个数.cpp
 * @author horiki
 * @date 2024-08-26
 * 
 * @brief 
 *  相当于求每个数的约数的集合的交集
 */

#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;
unordered_map<int, int> hh;

int main()
{
    int n; cin >> n;

    while (n --)
    {
        int x; cin >> x;
        for (int i = 2; i <= x / i; i ++)
            while (x % i == 0)
            {
                x /= i;
                hh[i] ++;
            }
        if (x > 1) hh[x] ++;
    }

    LL ans = 1;
    for (auto val : hh) ans = ans * (val.second + 1) % mod;
    cout << ans;

    return 0;
}
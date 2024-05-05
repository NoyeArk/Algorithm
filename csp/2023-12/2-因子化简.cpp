/**
 * @file 2-因子化简.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-05
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  质数分解，要注意数据类型的范围
 */

#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

typedef long long LL;

int main()
{
    int q; cin >> q;
    while (q --)
    {
        LL n, k; cin >> n >> k;
        unordered_map<int, int> h;
        
        for (int i = 2; i <= n / i; i ++)
            while (n % i == 0)
            {
                h[i] ++;
                n /= i;
            }

        LL ans = 1;
        for (auto it : h)
            if (it.second >= k) ans *= pow(it.first, it.second);
        cout << ans << endl;
    }
    return 0;
}
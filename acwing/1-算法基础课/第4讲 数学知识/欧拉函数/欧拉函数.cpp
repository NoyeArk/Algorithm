/**
 * @file 欧拉函数.cpp
 * @author horiki
 * @version 0.2
 * @date 2024-05-10 2024-05-30
 * 
 * @copyright Copyright (c) 2024
 * @brief 
 *  欧拉函数：1~n中与n互质的数的个数
 *  需要先分解质因数
 * 
 * 	2024-05-30：
 * 	f(n) = n * (1 - 1 / p1) * (1 - 1 / p2) * ... * (1 - 1 / ps)
 * 	在分解质因数的过程中求解
 */

#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    while (n --)
    {
        int x; cin >> x;
        int ans = x;
        for (int i = 2; i <= x / i; i ++)
            if (x % i == 0)
            {
                ans = ans / i * (i - 1);
                while (x % i == 0) x /= i;
            }
        if (x > 1) ans = ans / x * (x - 1);
        cout << ans << endl;
    }
    return 0;
}
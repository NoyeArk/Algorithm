/**
 * @file 试除法判定质数.cpp
 * @author horiki
 * @version 0.2
 * @date 2024-04-25 2024-05-09
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  质数：在所有大于1的整数中，如果只包含1和本身这两个约数，就为质数或素数。
 *  质数的判定：
 *      1.试除法
 *      2.只需要枚举 d<=n/d -> d²<=n -> d<=sqrt(n) 时间复杂度：O(sqrt(n))
 */

#include <iostream>
using namespace std;

bool is_prime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i <= n / i; i ++)
        if (n % i == 0) return false;
    return true;
}

int main()
{
    int n; cin >> n;
    while (n --)
    {
        int x; cin >> x;
        cout << (is_prime(x) ? "Yes" : "No") << endl;
    }
    return 0;
}
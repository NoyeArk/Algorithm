/**
 * @file 873. 欧拉函数.cpp
 * @author horiki
 * @date 2024-08-22
 * 
 * @brief 
 * 
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
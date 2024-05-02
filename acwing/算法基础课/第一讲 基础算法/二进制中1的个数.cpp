/**
 * @file 二进制中1的个数.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-02
 * @copyright Copyright (c) 2024
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
        int x, ans = 0; cin >> x;
        while (x)
        {
            ans += x & 1;
            x >>= 1;
        }
        cout << ans << " ";
    }
    return 0;
}
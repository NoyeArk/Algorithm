/**
 * @file 3-小蓝方程.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-18
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

int main()
{
    int x, y; cin >> x >> y;

    int ans = 0;
    // a取0 n任意
    ans += y + 1;
    // n取1 a取1~x
    ans += x;

    cout << ans;
    return 0;
}
/**
 * @file 801. 二进制中1的个数.cpp
 * @author horiki
 * @date 2024-09-14
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
        int x, cnt = 0; cin >> x;
        while (x) cnt += x & 1, x >>= 1;
        cout << cnt << " ";
    }

    return 0;
}
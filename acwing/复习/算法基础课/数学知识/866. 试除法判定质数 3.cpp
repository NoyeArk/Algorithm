/**
 * @file 866. 试除法判定质数 3.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

bool check(int x)
{
    if (x == 1) return false;
    for (int i = 2; i <= x / i; i ++)
        if (x % i == 0) return false;
    return true;
}

int main()
{
    int n; cin >> n;
    while (n --)
    {
        int x; cin >> x;
        cout << (check(x) ? "Yes" : "No") << endl;
    }

    return 0;
}
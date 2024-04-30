/**
 * @file 模拟队列.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-30
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 1000010;
int q[N], hh, tt = -1;

int main()
{
    int n; cin >> n;
    while (n --)
    {
        string op; cin >> op;
        if (op == "push")
        {
            int x; cin >> x;
            q[++ tt] = x;
        }
        else if (op == "pop") hh ++;
        else if (op == "query") cout << q[hh] << endl;
        else cout << (hh <= tt ? "NO" : "YES") << endl;
    }
    return 0;
}
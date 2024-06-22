/**
 * @file 模拟栈.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-06
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int stk[N], tt;

int main()
{
    int m; cin >> m;
    while (m --)
    {
        string op; cin >> op;
        if (op == "push")
        {
            int x; cin >> x;
            stk[++ tt] = x;
        }
        else if (op == "empty") cout << (tt == 0 ? "YES" : "NO") << endl;
        else if (op == "pop") tt --;
        else cout << stk[tt] << endl;
    }
    return 0;
}
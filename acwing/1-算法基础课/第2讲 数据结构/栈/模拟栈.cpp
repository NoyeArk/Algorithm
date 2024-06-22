/**
 * @file 模拟栈.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-29
 * @copyright Copyright (c) 2024
 * 
 * @brief
 *  
 */

#include <iostream>
using namespace std;

const int N = 1000010;
int stk[N], top;

int main()
{
    int n; cin >> n;
    while (n --)
    {
        string op; cin >> op;
        if (op == "push")
        {
            int x; cin >> x;
            stk[++ top] = x;
        }
        else if (op == "pop") top --;
        else if (op == "empty") cout << (top == 0 ? "YES" : "NO") << endl;
        else cout << stk[top] << endl;
    }
    return 0;
}
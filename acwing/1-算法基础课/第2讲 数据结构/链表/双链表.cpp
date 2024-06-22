/**
 * @file 双链表.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-28
 * @copyright Copyright (c) 2024
 * 
 * @brief
 *  
 */

#include <iostream>
using namespace std;

const int N = 1000010;
int e[N], ne[N], pre[N], idx;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = ne[a], pre[idx] = a, pre[ne[a]] = idx, ne[a] = idx ++;
}

int main()
{
    ne[0] = 1, pre[1] = 0, idx = 2;

    int m; cin >> m;
    while (m --)
    {
        string op; cin >> op;
        if (op == "L")
        {
            int x; cin >> x;
            add(0, x);
            // add(h, x);
        }
        else if (op == "R")
        {
            int x; cin >> x;
            add(pre[1], x);
            // add(t, x);
        }
        else if (op == "D")
        {
            int k; cin >> k;
            pre[ne[k + 1]] = pre[k + 1], ne[pre[k + 1]] = ne[k + 1];
        }
        else if (op == "IL")
        {
            int k, x; cin >> k >> x;
            add(pre[k + 1], x);
        }
        else 
        {
            int k, x; cin >> k >> x;
            add(k + 1, x);
        }
    }

    for (int i = ne[0]; i != 1; i = ne[i]) cout << e[i] << " ";
    return 0;
}
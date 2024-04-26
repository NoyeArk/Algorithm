/**
 * @file 单链表.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-26
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 1000010;
int h = -1, e[N], ne[N], idx = 1;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = ne[a], ne[a] = idx ++;
}

void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    int n; cin >> n;
    while (n --)
    {
        string op; cin >> op;
        if (op == "H")
        {
            int x; cin >> x;
            e[idx] = x, ne[idx] = h, h = idx ++;
        }
        else if (op == "D")
        {
            int k; cin >> k;
            if (k == 0) h = ne[h];
            else remove(k);
        }
        else 
        {
            int k, x; cin >> k >> x;
            add(k, x);
        }
    }

    for (int i = h; i != -1; i = ne[i])
        cout << e[i] << " ";

    return 0;
}
/**
 * @file 模拟散列表.cpp
 * @author horiki
 * @brief 
 * @version 0.1
 * @date 2024-05-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 100003;
int h[N], e[N], ne[N], idx;

void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x, ne[idx] = h[k], h[k] = idx ++;
}

bool find(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x) return true;
    return false;
}

int main()
{
    int n; cin >> n;
    memset(h, -1, sizeof h);
    while (n --)
    {
        string op; cin >> op;
        int x; cin >> x;
        if (op == "I") insert(x);
        else cout << (find(x) ? "Yes" : "No") << endl;
    }
    return 0;
}
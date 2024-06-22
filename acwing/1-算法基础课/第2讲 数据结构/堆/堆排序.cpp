/**
 * @file 堆排序.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-07
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int h[N], len;

void down(int u)
{
    int t = u;
    if (u * 2 <= len && h[u * 2] < h[t]) t = 2 * u;
    if (u * 2 + 1 <= len && h[u * 2 + 1] < h[t]) t = 2 * u + 1;
    if (t != u)
    {
        swap(h[t], h[u]);
        down(t);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> h[i];
    len = n;

    for (int i = n / 2; i; i --) down(i);

    while (m --)
    {
        cout << h[1] << " ";
        h[1] = h[len];
        len --;
        down(1);
    }

    return 0;
}
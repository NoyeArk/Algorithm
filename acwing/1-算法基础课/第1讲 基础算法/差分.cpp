/**
 * @file 差分.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-02
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  
 */

#include <iostream>
using namespace std;

const int N = 100010;
int a[N], diff[N];

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        diff[i] = a[i] - a[i - 1];
    }
    while (m --)
    {
        int l, r, c; cin >> l >> r >> c;
        diff[l] += c, diff[r + 1] -= c;
    }

    int tmp = 0;
    for (int i = 1; i <= n; i ++)
    {
        tmp += diff[i];
        cout << tmp << " ";
    }
    return 0;
}
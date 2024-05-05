/**
 * @file 数组元素的目标和.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-05
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int a[N], b[N];

int main()
{
    int n, m, x; cin >> n >> m >> x;

    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < m; i ++) cin >> b[i];

    int l = 0, r = m - 1;
    while (a[l] + b[r] != x)
    {
        if (a[l] + b[r] > x) r --;
        else l ++;
    }

    cout << l << " " << r;
    return 0;
}
/**
 * @file 前缀和.cpp
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
int a[N], pre[N];

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) 
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    while (m --)
    {
        int l, r; cin >> l >> r;
        cout << pre[r] - pre[l - 1] << endl;
    }

    return 0;
}
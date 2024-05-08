/**
 * @file 判断子序列.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-08
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
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int j = 1; j <= m; j ++) cin >> b[j];

    int i = 1;
    for (int j = 1; j <= m; j ++)
    {
        if (a[i] == b[j]) i ++;
        if (i == n + 1) 
        {
            cout << "Yes";
            break;
        }
    }
    if (i <= n) cout << "No";
    return 0;
}
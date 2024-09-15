/**
 * @file 2816. 判断子序列.cpp
 * @author horiki
 * @date 2024-09-14
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
    for (int i = 1; i <= m; i ++) cin >> b[i];

    int i = 1, j = 1;
    while (i <= n && j <= m)
        if (a[i] == b[j ++]) i ++;
    cout << (i > n ? "Yes" : "No");

    return 0;
}
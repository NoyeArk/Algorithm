/**
 * @file 898. 数字三角形.cpp
 * @author horiki
 * @date 2024-08-17
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;

const int N = 510;
int g[N][N], f[N][N];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++)   
        for (int j = 1; j <= i; j ++) cin >> g[i][j];

    memset(f, -0x3f, sizeof f);
    f[1][1] = g[1][1];
    for (int i = 2; i <= n; i ++)
        for (int j = 1; j <= i; j ++)
            f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + g[i][j];

    int ans = INT_MIN;
    for (int i = 1; i <= n; i ++) ans = max(ans, f[n][i]);
    cout << ans;
    return 0;
}
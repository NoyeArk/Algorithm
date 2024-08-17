/**
 * @file 2. 01背包问题 2.cpp
 * @author horiki
 * @date 2024-08-17
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 1010;
int v[N], w[N], f[N][N];

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= m; j ++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }

    cout << f[n][m];
    return 0;
}
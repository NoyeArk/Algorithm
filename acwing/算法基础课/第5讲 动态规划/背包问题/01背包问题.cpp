/**
 * @file 01背包问题.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-01
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 1010;
int v[N], w[N];
int f[N][N];

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            f[i][j] = f[i - 1][j];  // 不选第i件物品
            if (j >= v[i]) 
				f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    cout << f[n][m];
    return 0;
}

// ********************优化版本******************
#include <iostream>
using namespace std;

const int N = 1010;
int v[N], w[N];
int f[N];

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i ++)
        for (int j = m; j >= v[i]; j --)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    cout << f[m];
    return 0;
}
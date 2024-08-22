/**
 * @file 9. 分组背包问题 1.cpp
 * @author horiki
 * @date 2024-08-22
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 110;
int v[N][N], w[N][N], s[N];
int f[N][N];

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        cin >> s[i];
        for (int j = 1; j <= s[i]; j ++)
            cin >> v[i][j] >> w[i][j];
    }

    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= m; j ++)
        {
            f[i][j] = f[i - 1][j];
            for (int k = 1; k <= s[i]; k ++)
                if (j >= v[i][k]) 
                    f[i][j] = max(f[i][j], f[i - 1][j - v[i][k]] + w[i][k]);
        }

    cout << f[n][m];
    return 0;
}
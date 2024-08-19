/**
 * @file 4. 多重背包问题 2.cpp
 * @author horiki
 * @date 2024-08-19
 * 
 * @brief 
 *  和01背包、完全背包不同的是要遍历每一个可以选择的数目
 */

#include <iostream>
using namespace std;

const int N = 1010;
int v[N], w[N], s[N], f[N][N];

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> v[i] >> w[i] >> s[i];

    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= m; j ++)
            for (int k = 0; k <= s[i] && k * v[i] <= j; k ++)
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
        
    cout << f[n][m];
    return 0;
}
/**
 * @file 3. 完全背包问题.cpp
 * @author horiki
 * @date 2024-08-16
 * 
 * @brief 
 *  状态计算：
 *      不选第i个物品：f[i][j] = f[i - 1][j]
 *      选1个：f[i][j] = f[i - 1][j - v[i]] + w[i]
 *      选2个：f[i][j] = f[i - 1][j - 2 * v[i]] + 2 * w[i]
 *      ...
 *      选n个：f[i][j] = f[i - 1][j - n * v[i]] + n * w[i]
 *  则f[i][j] = max(f[i - 1][j], 选1个，选2个，...，选n个)
 *  
 */

#include <iostream>
using namespace std;

const int N = 1010;
int v[N], w[N], f[N];

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i ++)
        for (int j = v[i]; j <= m; j ++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m];
    return 0;
}
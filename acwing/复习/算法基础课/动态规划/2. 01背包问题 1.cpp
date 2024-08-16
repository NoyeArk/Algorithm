/**
 * @file 2. 01背包问题 1.cpp
 * @author horiki
 * @date 2024-08-16
 * 
 * @brief 
 *  状态表示：f[i][j]表示选择第i个物品体积不超过j的最大价值
 *  状态计算：
 *      不选第i个
 *      选第i个
 */

#include <iostream>
using namespace std;

typedef long long LL;

const int N = 1010;
int v[N], w[N], f[N];

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i ++)
        for (int j = m; j >= v[i]; j --)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m];
    return 0;
}
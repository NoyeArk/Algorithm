/**
 * @file 最短编辑距离.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-05
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  猜想：是否有这样一个性质，对A的操作可以转换所有对B的操作
 *  1.状态表示：f[i][j]
 *      1.1 集合：所有将a[1~i]变成b[1~j]的操作方式
 *      1.2 属性：所有操作方式的操作次数的最小值
 *  2.状态计算：
 *      最后一步操作有三种类型
 *      ①删除a[i],最小值为f[i-1][j] + 1
 *      ②增加a[i],f[i][j-1] + 1
 *      ③修改a[i],a[i] != b[j] -> f[i-1][j-1] + 1
 */

#include <iostream>
using namespace std;

const int N = 1010;
char a[N], b[N];
int f[N][N];

int main()
{
    int n, m; cin >> n >> a + 1 >> m >> b + 1;
    for (int i = 0; i <= m; i ++) f[0][i] = i;
    for (int i = 0; i <= n; i ++) f[i][0] = i;

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }
            
    cout << f[n][m];
    return 0;
}
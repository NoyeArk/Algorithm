/**
 * @file 滑雪.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-14
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  1.状态表示：
 *      f[i][j]表示在[i, j]能够滑行的最远距离
 *  2.状态计算：
 *      判断四个方向，分别进行dp
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 310;
int n, m; 
int h[N][N], f[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dp(int x, int y)
{
    int &v = f[x][y];
    if (v != -1) return v;

    v = 1;
    for (int i = 0; i < 4; i ++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 1 || a > n || b < 1 || b > m || h[a][b] >= h[x][y]) continue;
        v = max(v, dp(a, b) + 1);
    }
    return v;
}

int main()
{
    memset(f, -1, sizeof f);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> h[i][j];

    int ans = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            ans = max(ans, dp(i, j));

    cout << ans;
    return 0;
}
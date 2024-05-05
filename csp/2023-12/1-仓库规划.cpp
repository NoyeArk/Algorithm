/**
 * @file 1-仓库规划.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-05
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  观察到数据大小为10^3，可以使用O(n²)的时间复杂度
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100010;
int n, m;
int a[N][15];

bool cmp(int u, int v)
{
    for (int k = 1; k <= m; k ++)
        if (a[u][k] >= a[v][k])
            return false;
    return true;
}

int main()
{
    cin >> n >> m; 
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) 
            cin >> a[i][j];

    for (int i = 1; i <= n; i ++)
    {
        int ans = 0;
        for (int j = 1; j <= n; j ++)
        {
            if (i == j) continue;
            if (cmp(i, j)) 
            {
                ans = j;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
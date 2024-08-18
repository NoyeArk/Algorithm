/**
 * @file 152. 城市游戏.cpp
 * @author horiki
 * @date 2024-08-17
 * 
 * @brief 
 *  题意：找全部由F构成的最大矩形的面积
 *  就比如告诉你这道题用到的算法是单调栈，但是你能想出来怎么做吗？
 *  为什么感觉把思想转换成代码很困难？感觉还是对模板不熟悉
 *  就像这题写单调栈，写的时候自己也不确保一定对
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int n, m;
char g[N][N];
int h[N][N];
int q[N], l[N], r[N];

void cal(int a[], int l[])
{
    // 求解左边第一个比我小的数
    int tt = 0;
    a[0] = -1;
    for (int i = 1; i <= m; i ++)
    {
        while (a[q[tt]] >= a[i]) tt --;
        l[i] = q[tt] + 1;
        q[++ tt] = i;
    }
}

int work(int a[])
{
    cal(a, l);
    reverse(a + 1, a + 1 + m);
    cal(a, r);
    reverse(a + 1, a + 1 + m);
    
    int res = 0;
    for (int i = 1; i <= m; i ++)
    {
        int left = l[i];
        int right = m + 1 - r[m + 1 - i];
        res = max(res, a[i] * (right - left + 1));
    }
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'F') h[i][j] = h[i - 1][j] + 1;
            else h[i][j] = 0;
        }
        
    int ans = 0;
    for (int i = 1; i <= n; i ++) ans = max(ans, work(h[i]));
    cout << ans * 3;

    return 0;
}
/**
 * @file 借教室.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-15
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  1.涉及到区间问题，考虑差分？
 *      不可以，时间复杂度太高
 *  2.使用二分，需要找一个单调性
 *      如果订单满足，需要修改原数组，但是修改起来时间复杂度很高
 *      单调性：前k个订单满足，k+1后就不满足
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 1000010;
int n, m;
long long r[N], diff[N];
int w[N], st[N], ed[N];

bool check(int mid)
{
    // 判断前mid个订单是否满足要求
    memset(diff, 0, sizeof diff);
    for (int i = 1; i <= mid; i ++)
        diff[st[i]] += w[i], diff[ed[i] + 1] -= w[i];
    long long res = 0;
    for (int i = 1; i <= n; i ++)
    {
        res += diff[i];
        if (res > r[i]) return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> r[i];
    for (int i = 1; i <= m; i ++) cin >> w[i] >> st[i] >> ed[i];

    int l = 0, r = m; 
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    
    if (r != m) cout << -1 << endl << r + 1;
    else cout << 0;

    return 0;
}
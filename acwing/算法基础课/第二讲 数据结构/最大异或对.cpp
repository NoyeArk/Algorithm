/**
 * @file 最大异或对.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-30
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  如果没有思路就先用暴力，然后再想怎么进行优化
 *  固定Ai，从A1~An中选出一个数Aj，是的Ai^Aj最大
 */

#include <iostream>
using namespace std;

const int N = 100010, M = 3000000;
int n;
int son[M][2], idx;
int a[N];

void insert(int x)
{
    int p = 0;
    for (int i = 30; ~i; i --)
    {
        int s = son[p][x >> i & 1];
        if (!s) s = ++ idx;
        p = s;
    }
}

int query(int x)
{
    int res = 0, p = 0;
    for (int i = 30; ~i; i --)
    {
        int s = x >> i & 1;
        if (son[p][!s])
        {
            res += 1 << i;
            p = son[p][!s];
        }
        else p = son[p][s];
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        insert(a[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++)
        ans = max(ans, query(a[i]));

    cout << ans;
    return 0;
}
/**
 * @file 滑动窗口.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-04
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  相当于实现了一个插入受限的双端队列
 */

#include <iostream>
using namespace std;

const int N = 1000010;
int a[N];
int q[N], hh, tt = -1;

int main()
{
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    // 找最小值
    for (int i = 1; i <= n; i ++)
    {
        if (hh <= tt && i - k + 1 > q[hh]) hh ++;
        while (hh <= tt && a[q[tt]] > a[i]) tt --;
        q[++ tt] = i;
        if (i >= k) cout << a[q[hh]] << " ";
    }
    cout << endl;
    hh = 0, tt = -1;
    // 找最大值
    for (int i = 1; i <= n; i ++)
    {
        if (hh <= tt && i - k + 1 > q[hh]) hh ++;
        while (hh <= tt && a[q[tt]] < a[i]) tt --;
        q[++ tt] = i;
        if (i >= k) cout << a[q[hh]] << " ";
    }

    return 0;
}
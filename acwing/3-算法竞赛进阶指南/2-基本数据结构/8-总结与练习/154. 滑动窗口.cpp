/**
 * @file 154. 滑动窗口.cpp
 * @author horiki
 * @date 2024-08-21
 * 
 * @brief 
 *  感觉做题的时候可以写一些注释 让自己的思路更加清晰
 */

#include <iostream>
using namespace std;

const int N = 1000010;
int a[N], n, k;
int q[N], hh, tt = -1;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    // 求出滑动窗口中的最小值
    for (int i = 1; i <= n; i ++)
    {
        // 先将滑动窗口中超出当前窗口中的数移出
        // 当前位置为i 距离k远的元素的位置为i - k + 1
        while (hh <= tt && q[hh] < i - k + 1) hh ++;
        // 将当前窗口中比a[i]大的元素移出
        while (hh <= tt && a[q[tt]] > a[i]) tt --;
        q[++ tt] = i;
        // 判断是否要输出答案
        if (i >= k) cout << a[q[hh]] << " ";
    }
    cout << endl;

    hh = 0, tt = -1;
    // 求最大值
    for (int i = 1; i <= n; i ++)
    {
        while (hh <= tt && q[hh] < i - k + 1) hh ++;
        while (hh <= tt && a[q[tt]] < a[i]) tt --;
        q[++ tt] = i;
        if (i >= k) cout << a[q[hh]] << " ";
    }

    return 0;
}
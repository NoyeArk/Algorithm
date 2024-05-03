/**
 * @file 2-垦田计划.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-30
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  如果不投入任何资源，那么完成时间为最长的那一个
 *  1.每次投入耗时最长的任务中所需要的资源
 *  2.然后再从剩下的任务中选择耗时最长的继续投入资源
 *  3.一直循环，直到手中的资源不够继续投入
 *  
 *  ·如何选出耗时最长的任务？使用优先队列，默认按第一个元素排序
 *  正解：使用二分法，直接二分答案，O(nlogn)
 */

#include <iostream>
using namespace std;

const int N = 100010;
int n, m, k;
int t[N], c[N];

bool check(int mid)
{
    // 最少需要mid天
    int res = m;
    for (int i = 1; i <= n; i ++)
    {
        if (t[i] <= mid) continue;
        res -= (t[i] - mid) * c[i];
        if (res < 0) return false;
    }
    return true;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++) cin >> t[i] >> c[i];

    int l = 1, r = 100000;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l;
    return 0;
}
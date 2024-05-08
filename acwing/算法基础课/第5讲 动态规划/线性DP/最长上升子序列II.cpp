/**
 * @file 最长上升子序列II.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-04
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  1.状态表示
 *      1.1 属性：f[i]表示以i结尾的单调递增的子序列的最大长度
 *      1.2 集合：
 *  2.状态计算
 *      2.1 找到i左边比i小的数j的下标 O(n²)
 *          f[i] = f[j] + 1
 *  3.n为1o^5，使用两层循环会超时，使用O(nlogn)
 */

#include <iostream>
using namespace std;

const int N = 100010;
int n;
int a[N], q[N];  // 所有不同长度的上升子序列结尾最小值

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    int len = 0;
    q[0] = -2e9;
    for (int i = 1; i <= n; i ++)
    {
        int l = 0, r = len;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (q[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1);
        q[r + 1] = a[i];
    }

    cout << len;
    return 0;
}

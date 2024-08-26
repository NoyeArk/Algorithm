/**
 * @file 896. 最长上升子序列 II.cpp
 * @author horiki
 * @date 2024-08-26
 * 
 * @brief 
 *  数据范围变大，使用之前的做法会TLE
 *  存储不同长度的上升子序列的结尾的最小值，这个最小值一定是单调递增的
 */

#include <iostream>
using namespace std;

const int N = 100010;
int a[N], f[N];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    int len = 0;
    for (int i = 1; i <= n; i ++)
    {
        int l = 0,  r = len;
        while (l < r)
        {
            // f[mid]代表长度为mid的最长上升序列的结尾的最小值
            int mid = l + r + 1 >> 1;
            if (f[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        // 可以将a[i]放到长度为r的序列后面构成长度为r+1的序列
        len = max(len, r + 1);
        f[r + 1] = a[i];
    }
    cout << len;
    return 0;
}
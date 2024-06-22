/**
 * @file 最长上升子序列.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-03
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  1.状态表示
 *      1.1 属性：f[i]表示以i结尾的单调递增的子序列的最大长度
 *      1.2 集合：
 *  2.状态计算
 *      2.1 找到i左边比i小的数j的下标 O(n²)
 *          f[i] = f[j] + 1
 */

#include <iostream>
#include <utility>
using namespace std;

typedef pair<int, int> PII;

const int N = 1010;
int a[N], f[N], tt;
PII stk[N];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        for (int j = 1; j < i; j ++)
            if (a[j] < a[i] && f[j] > f[i])
                f[i] = f[j];
        f[i] ++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++) ans = max(ans, f[i]);
    cout << ans << endl;
    
    return 0;
}
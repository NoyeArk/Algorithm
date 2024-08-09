/**
 * @file 131. 直方图中最大的矩形.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  对于每个矩形来说，它所构成的最大矩形的面积取决于位于它左边和右边的第一个比起小的矩形的高度之间的距离
 *  因此可以使用单调栈求出第i个矩形左边第一个比起小的矩形的位置l[i]，和右边的r[i]
 */

#include <iostream>
#include <stack>
using namespace std;

typedef long long LL;

const int N = 100010;
int n;
LL h[N], l[N], r[N];
stack<int> stk;

void work()
{
    h[0] = h[n + 1] = -1;
    stk = stack<int>{};
    stk.push(0);
    for (int i = 1; i <= n; i ++) cin >> h[i];
    // 求解l[i]
    for (int i = 1; i <= n; i ++)
    {
        while (stk.size() && h[stk.top()] >= h[i]) stk.pop();
        l[i] = stk.top();
        stk.push(i);
    }

    stk = stack<int>{};
    stk.push(n + 1);
    // 求解r[i]
    for (int i = n; i; i --)
    {
        while (stk.size() && h[stk.top()] >= h[i]) stk.pop();
        r[i] = stk.top();
        stk.push(i);
    }

    LL ans = 0;
    for (int i = 1; i <= n; i ++)
        ans = max(ans, h[i] * (r[i] - l[i] - 1));
    cout << ans << endl;
}

int main()
{
    while (cin >> n, n) work();
    return 0;
}
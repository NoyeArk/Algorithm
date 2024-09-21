/**
 * @file 799. 最长连续不重复子序列.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int a[N], st[N];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    int i = 1, j = 1, ans = 0;
    while (i <= n && j <= n)
    {
        while (!st[a[j]] && j <= n) st[a[j ++]] ++;
        ans = max(ans, j - i);
        st[a[i ++]] --;
    }

    cout << ans;
    return 0;
}
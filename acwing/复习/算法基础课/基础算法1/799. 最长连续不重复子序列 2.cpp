/**
 * @file 799. 最长连续不重复子序列 2.cpp
 * @author horiki
 * @date 2024-09-12
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int a[N], cnt[N];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    int ans = 0, i = 1, j = 1;
    while (j <= n)
    {
        if (!cnt[a[j]]) cnt[a[j]] = 1, j ++;
        else while (cnt[a[j]]) cnt[a[i ++]] --;
        ans = max(ans, j - i);
    }

    cout << ans;
    return 0;
}
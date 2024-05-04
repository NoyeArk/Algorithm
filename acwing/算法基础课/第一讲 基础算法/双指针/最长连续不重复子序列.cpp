/**
 * @file 最长连续不重复子序列.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-04
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  时间复杂度O(2n)
 */

#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 100010;
int a[N], cnt[N];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    int ans = 0;
    for (int i = 1, j = 1; i <= n; i ++)
    {
        cnt[a[i]] ++;
        while (cnt[a[i]] > 1) cnt[a[j]] --, j ++;
        ans = max(ans, i - j + 1);
    }
        
    cout << ans;
    return 0;
}
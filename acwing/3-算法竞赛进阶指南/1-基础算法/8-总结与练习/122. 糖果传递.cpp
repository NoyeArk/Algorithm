/**
 * @file 122. 糖果传递.cpp
 * @author horiki
 * @date 2024-09-04
 * 
 * @brief 
 *  首先想一下这题用到什么知识点，对于每个少于糖果平均数的小朋友，他需要从离他最近的小朋友手里得到糖
 *  
 */

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 1000010;
int a[N], s[N];

int main()
{
    int n; cin >> n;

    LL sum = 0;
    for (int i = 1; i <= n; i ++) 
    {
        cin >> a[i];
        sum += a[i];
    }
    auto avg = sum / n;
    for (int i = 1; i <= n; i ++) a[i] -= avg;
    for (int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];

    sort(s + 1, s + 1 + n);

    LL ans = 0;
    for (int i = 1; i <= n; i ++) ans += abs(s[i] - s[(n + 1) / 2]);
    cout << ans;

    return 0;
}
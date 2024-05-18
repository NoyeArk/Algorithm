/**
 * @file 2-最小值取余.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-18
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010, P = 998244353;
int a[N];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    sort(a + 1, a + 1 + n);

    long long ans = 0;
    for (int i = 1; i <= n; i ++)
        ans = (ans * 10 + a[i]) % P;

    cout << ans;
    return 0;
}
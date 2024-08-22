/**
 * @file 895. 最长上升子序列.cpp
 * @author horiki
 * @date 2024-08-22
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 1010;
int f[N], a[N];

int main()
{
    int n, ans = 0; cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        for (int j = 1; j < i; j ++)
            if (a[j] < a[i]) 
                f[i] = max(f[i], f[j] + 1), ans = max(ans, f[i]);
    }

    cout << ans + 1;
    return 0;
}
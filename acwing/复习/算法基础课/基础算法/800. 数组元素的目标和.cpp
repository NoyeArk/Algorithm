/**
 * @file 800. 数组元素的目标和.cpp
 * @author horiki
 * @date 2024-09-12
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int a[N], b[N];

int main()
{
    int n, m, x; cin >> n >> m >> x;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= m; i ++) cin >> b[i];
    int i = 1, j = m;
    while (i <= n && 1 <= j)
    {
        int sum = a[i] + b[j];
        if (sum < x) i ++;
        else if (sum == x) break;
        else j --;
    }
    cout << i - 1 << " " << j - 1;
    return 0;
}
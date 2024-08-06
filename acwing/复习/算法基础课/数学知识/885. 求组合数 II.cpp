/**
 * @file 885. 求组合数 I .cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-06
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 60010;
int f[N];

int main()
{
    int n; cin >> n;

    f[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] * (4 * i - 2) / (i + 1);
    cout << f[n];

    return 0;
}
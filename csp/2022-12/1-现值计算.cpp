/**
 * @file 现值计算.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-08
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  1.从第一年开始计算，第一年的时候第0年的加上利息
 *  认真审题！！！
 */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n; double eps; cin >> n >> eps;

    double ans = 0;
    for (int i = 0; i <= n; i ++) 
    {
        int x; cin >> x;
        ans += x * pow(1 + eps, -1 * i);
    }
    cout << ans << endl;

    return 0;
}
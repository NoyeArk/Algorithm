/**
 * @file 数的三次方根.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-10
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

int main()
{
    double n; cin >> n;
    double l = -100, r = 100;
    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= n) r = mid;
        else l = mid;
    }
    printf("%.6lf", r);
    return 0;
}
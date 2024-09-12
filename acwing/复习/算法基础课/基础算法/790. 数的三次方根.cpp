/**
 * @file 790. 数的三次方根.cpp
 * @author horiki
 * @date 2024-09-12
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

int main()
{
    double n; cin >> n;
    double l = 0, r = 100;
    while (r - l > 1e-6)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid < n) l = mid;
        else r = mid;
    }
    printf("%.6lf", r);
    return 0;
}
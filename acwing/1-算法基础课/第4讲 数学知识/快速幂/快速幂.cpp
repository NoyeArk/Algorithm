/**
 * @file 快速幂.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-06
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  快速地求出一个数的k次方 % p，时间复杂度为O(logk)
 *  反复平方法，预处理出来一些数，使用二进制优化
 */

#include <iostream>
using namespace std;

typedef long long LL;

// a ^ k % p
int qpow(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main()
{
    int n; cin >> n;
    while (n --)
    {
        int a, b, p; cin >> a >> b >> p;
        cout << qpow(a, b, p) << endl;
    }
    return 0;
}
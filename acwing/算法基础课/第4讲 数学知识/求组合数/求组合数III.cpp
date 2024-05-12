/**
 * @file 求组合数III.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-11
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

typedef long long LL;

int qmi(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

int C(int a, int b, int p)
{
    if (b > a) return 0;
    int res = 1;
    for (int i = 1, j = a; i <= b; i ++, j --)
    {
        // 相乘可能大于int 需要先转换成LL
        res = (LL)res * j % p;
        res = (LL)res * qmi(i, p - 2, p) % p;
    }
    return res;
}

// 卢卡斯定理 C(a, b) % p = lucas(a / p, b / p, p) * C(a % p, b % p, p);
int lucas(LL a, LL b, int p)
{
    if (a < p && b < p) return C(a, b, p);
    return (LL)lucas(a / p, b / p, p) * C(a % p, b % p, p) % p;
}

int main()
{
    int n; cin >> n;
    while (n --)
    {
        LL a, b;
        int p; cin >> a >> b >> p;
        cout << lucas(a, b, p) << endl;
    }
    return 0;
}
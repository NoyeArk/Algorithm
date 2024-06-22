/**
 * @file 快速幂求逆元.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-07
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

typedef long long LL;

const int N = 100010;

int qmi(int a, int k, int p)
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
        int a, p; cin >> a >> p;
        int res = qmi(a, p - 2, p);
        if (a % p) cout << res << endl;
        else cout << "impossible" << endl;
    }

    return 0;
}
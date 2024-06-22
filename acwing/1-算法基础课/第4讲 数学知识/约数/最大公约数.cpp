/**
 * @file 最大公约数.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-03
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  思路1：先分别求出两个数各自的约数，然后对他们各自的约数集求交集，然后输出交集中最大的一个数
 *      结果：超时
 *  思路2：在求一个数的约数的同时判断是否为另一个数的约数
 *      结果：超时
 *  解决方法：欧几里得算法（辗转相除法）
 *      a mod b = a - a / b * b
 *              = a - c * b
 *      a, b的最大公约数 = b, a - c * b的最大公约数
 *   -> a, b的最大公约数 = b, a mod b的最大公约数
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 思路1
vector<int> intersection(vector<int> a, vector<int> b)
{
    vector<int> res;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
    return res;
}

vector<int> get_divisors(int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i ++)
        if (x % i == 0)
        {
            res.push_back(i);
            if (x / i != i) res.push_back(x / i);
        }
    sort(res.begin(), res.end());
    return res;
}

// 思路2
int get_common_divisors(int x, int y)
{
    int res = 1;
    for (int i = 1; i <= x / i; i ++)
        if (x % i == 0 && y % (x / i) == 0)
            return x / i;
        else if (x % i == 0 && y % i == 0)
            res = i;
    // sort(res.begin(), res.end());
    return res;
}

// 解决方法
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n; cin >> n;
    while (n --)
    {
        int a, b; cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    return 0;
}
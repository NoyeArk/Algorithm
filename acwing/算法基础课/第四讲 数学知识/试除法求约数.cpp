/**
 * @file 试除法求约数.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-30
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  试除法求一个数的所有约数：
 *      从小到达枚举所有约数，只枚举小的那一个
 *      时间复杂度：O(nlogn)
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> get_divisors(int n)
{
    vector<int> res;

    for (int i = 1; i <= n / i; i ++)
        if (n % i == 0)
        {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    int n; cin >> n;

    while (n --)
    {
        int x; cin >> x;
        auto ans = get_divisors(x);
        for (auto t : ans) cout << t << " ";
        cout << endl;
    }

    return 0;
}
/**
 * @file 计数问题.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-11
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  1.暴力做法 TLE
 *  2.动态规划
 *      count(n, x)：求出从1~n中x出现的次数
 *      [a, b] = count(b, x) - count(a - 1, x)
 *      求出1在每一位上出现的次数
 *      2.1 1 <= xxx1yyy <= abcdefg
 *        (1) xxx = 0~abc-1 , yyy = 0~999 一共有abc * 1000
 *        (2) xxx = abc
 *              d = 0 abc1yyy > abc0efg 0个
 *              d = 1 abc1yyy abc1efg efg + 1个
 *              d > 1 abc1yyy abcdefg 1000个
 *       边界情况：
 *          1.当分析0出现的次数时，abc不能是000,所以只能1 ~ abc-1
 */

#include <iostream>
#include <vector>
using namespace std;

int get(vector<int>& num, int l, int r)
{
    int res = 0;
    for (int i = l; i >= r; i --) res = res * 10 + num[i];
    return res;
}

int power10(int x)
{
    int res = 1;
    while (x --) res *= 10;
    return res;
}

int count(int n, int x)
{
    if (!n) return 0;
    vector<int> num;
    while (n)
    {
        num.push_back(n % 10);
        n /= 10;
    }

    n = num.size();
    
    int res = 0;
    for (int i = n - 1 - !x; i >= 0; i --)
    {
        if (i < n - 1) 
        {
            res += get(num, n - 1, i + 1) * power10(i);
            if (!x) res -= power10(i);
        }
        if (num[i] == x) res += get(num, i - 1, 0) + 1;
        else if (num[i] > x) res += power10(i);
    }
    return res;
}

int main()
{
    int a, b;
    while (cin >> a >> b, a)
    {
        if (a > b) swap(a, b);
        for (int i = 0; i <= 9; i ++)
            cout << count(b, i) - count(a - 1, i) << " ";
        cout << endl;
    }
    return 0;
}

/** 暴力
for (int i = min(a, b); i <= max(a, b); i ++)
            work(i);
        for (int i = 0; i < 10; i ++)
            cout << cnt[i] << " ";
        cout << endl;
 */
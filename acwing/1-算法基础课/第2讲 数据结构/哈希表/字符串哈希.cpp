/**
 * @file 字符串哈希.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-04
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  字符串前缀哈希法
 *  1. 例如：str = "abcde"
 *      h[1] = "a"的哈希值
 *      h[2] = "ab"的哈希值
 *      h[3] = "abc"的哈希值
 *  2. 如何定义每一个字符串的哈希值
 *      把每一个字符串看成是一个p进制的数
 *      "abcd"的哈希值：把a当成1，b当作2
 *          hash = 1*p^3 + 2*p^2 + 3*p^1 + 4*p^0
 *      可能数字比较大，需要取模运算
 *          hash = hash % mod
 *  3. 把任何一个字符串映射到0~(mod-1)之间的数
 *  4. 注意：
 *      4.1 不要把某一个字母映射为0
 *      4.2 这里字符串哈希方法假定不会存在冲突，
 *          p = 131或13331，mod = 2^64，大部分不会出现冲突
 *  5. 可以利用前缀哈希快速算出任何一个字串的哈希值
 *      已知h[l-1]和h[r], 求h[l, r]子串的哈希值
 *      h[l, r] = h[r] - h[l - 1] * p^(r - l + 1)
 */

#include <iostream>
using namespace std;

typedef unsigned long long ULL;

const int N = 100010, P = 13331;
int n, m;
char str[N];
ULL h[N], p[N];

ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    cin >> n >> m >> str + 1;
    p[0] = 1;
    for (int i = 1; i <= n; i ++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }
    while (m --)
    {
        int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
        if (get(l1, r1) == get(l2, r2)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
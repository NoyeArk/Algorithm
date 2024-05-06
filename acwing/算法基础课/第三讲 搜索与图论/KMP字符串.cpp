/**
 * @file KMP字符串.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-06
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  1.朴素做法：循环遍历每个串，时间复杂度为O(n*m)，空间复杂度为1
 *  2.KMP
 */

#include <iostream>
using namespace std;

const int N = 10000010;
char p[N], s[N];
int ne[N];

int main()
{
    int n; cin >> n >> p + 1;
    int m; cin >> m >> s + 1;

    for (int i = 2, j = 0; i <= n; i ++)
    {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= m; i ++)
    {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++;
        if (j == n)
        {
            cout << i - n << " "; 
            j = ne[j];
        }
    }

    return 0;
}
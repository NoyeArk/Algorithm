/**
 * @file KMP字符串.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-24
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 */

#include <iostream>
using namespace std;

const int N = 100010, M = 1000010;

int n, m;
int ne[N];
char s[M], p[N];

int main()
{
    cin >> n >> p + 1 >> m >> s + 1;

    for (int i = 2, j = 0; i <= n; i ++)
    {
        while (j != 0 && p[i] != p[j + 1]) j = ne[j];
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
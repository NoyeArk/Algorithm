/**
 * @file 835. Trie字符串统计 2.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-11
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int son[N][26], idx;
int cnt[N];

void insert(string str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++)
    {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++;
}

int query(string str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++)
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    int n; cin >> n;
    while (n --)
    {
        char op; string x; cin >> op >> x;
        if (op == 'I') insert(x);
        else cout << query(x) << endl;
    }

    return 0;
}
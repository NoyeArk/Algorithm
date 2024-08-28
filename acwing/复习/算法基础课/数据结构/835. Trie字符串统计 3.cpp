/**
 * @file 835. Trie字符串统计 3.cpp
 * @author horiki
 * @date 2024-08-28
 * 
 * @brief 
 *  Trie树的最大深度是字符串的长度，每个节点后面可能有26个孩子节点
 */

#include <iostream>
using namespace std;

const int N = 100010;
int son[N][26], idx;
int cnt[N];
string str;

void insert()
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

int query()
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
        char op; cin >> op >> str;
        if (op == 'I') insert();
        else cout << query() << endl;
    }

    return 0;
}
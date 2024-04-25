/**
 * @file Trie字符串统计.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-25
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  Trie：高效地存储和查找字符串集合的数据结构
 *      使用范围：字母个数不是很多
 *  例题：abcedf
 *      1.从前向后遍历每个字符，从根节点开始，判断是否有a结点，如果没有就创建出来，以此类推。
 *      2.在存储的时候，在每个单词的结尾打上一个标记，表示有单词以当前结点结尾。
 *      3.高效查询某个单词是否存在。
 */

#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int son[N][26], cnt[N], idx;  // 下标为0，既是根节点，又是空结点
char str[N];

void insert(char str[])
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

int query(char str[])
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
        string op; cin >> op >> str;
        if (op == "I") insert(str);
        else cout << query(str) << endl;
    }
    return 0;
}
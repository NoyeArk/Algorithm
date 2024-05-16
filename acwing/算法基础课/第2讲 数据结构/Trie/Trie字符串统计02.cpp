/**
 * @file Trie字符串统计02.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-16
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int son[N][26], cnt[N], idx;
char str[N];

void insert(char str[])
{
	int p = 0;
	for (int i = 0; str[i]; i ++)
	{
		int u = str[i] - 'a';
		// 从根节点开始遍历 如果没有这个结点 创建这个结点
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
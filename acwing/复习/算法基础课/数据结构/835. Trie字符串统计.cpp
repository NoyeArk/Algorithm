/**
 * @file 835. Trie字符串统计.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-07-29
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int son[N][26], cnt[N], idx;
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
		string op; cin >> op >> str;
		if (op == "I") insert();
		else cout << query() << endl;
	}

	return 0;
}
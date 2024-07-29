/**
 * @file 142. 前缀统计.cpp
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

const int N = 1000010;
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
	int p = 0, res = 0;
	for (int i = 0; str[i]; i ++)
	{
		int u = str[i] - 'a';
		if (!son[p][u]) return res;
		p = son[p][u], res += cnt[p];
	}
	return res;
}

int main()
{
	int n, m; cin >> n >> m;
	while (n --)
	{
		cin >> str;
		insert();
	}

	while (m --)
	{
		cin >> str;
		cout << query() << endl;
	}

	return 0;
}
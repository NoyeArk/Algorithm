/**
 * @file 143. 最大异或对.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-24
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 100010, M = 3000000;
int n, a[N];
int son[M][2], idx;

void insert(int x)
{
	int p = 0;
	for (int i = 30; ~i; i --)
	{
		int &u = son[p][x >> i & 1];
		if (!u) u = ++ idx;
		p = u;
	}
}

int query(int x)
{
	int res = 0, p = 0;
	for (int i = 30; ~i; i --)
	{
		int s = x >> i & 1;
		if (son[p][!s])
		{
			res += 1 << i;
			p = son[p][!s];
		}
		else p = son[p][s];
	}
	return res;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		insert(a[i]);
	}

	int ans = 0;
	for (int i = 1; i <= n; i ++)
		ans = max(ans, query(a[i]));

	cout << ans;
	return 0;
}
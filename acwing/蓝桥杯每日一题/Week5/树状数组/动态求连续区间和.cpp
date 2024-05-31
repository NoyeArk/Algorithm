/**
 * @file 动态求连续区间和.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-31
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int tr[N];

int lowbit(int x)
{
	return x & -x;
}

void add(int x, int v)
{
	for (int i = x; i < N; i += lowbit(i))
		tr[i] += v;
}

int ask(int x)
{
	int res = 0;
	for (int i = x; i; i -= lowbit(i))
		res += tr[i];
	return res;
}

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i ++) 
	{
		int x; cin >> x;
		add(i, x);
	}

	while (m --)
	{
		int k, a, b; cin >> k >> a >> b;
		if (k == 0) cout << ask(b) - ask(a - 1) << endl;
		else add(a, b);
	}

	return 0;
}
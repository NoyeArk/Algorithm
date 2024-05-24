/**
 * @file 飞机降落.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-24
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 15;
int n;
int t[N], d[N], l[N];
int st[N];  // 标志是否降落

bool dfs(int u, int time)
{
	if (time > t[u] + d[u]) return false;

	time = max(time, t[u]) + l[u];
	bool flag = true;  // 标志是否在u之后还有飞机未降落

	for (int i = 1; i <= n; i ++)
	{
		if (st[i]) continue;
		flag = false;
		st[i] = true;
		if (dfs(i, time)) return true;
		st[i] = false;
	}

	return flag;
}

int main()
{
	int m; cin >> m;
	while (m --)
	{
		cin >> n;
		for (int i = 1; i <= n; i ++) cin >> t[i] >> d[i] >> l[i];
		bool is_ok = false;
		for (int i = 1; i <= n; i ++)
		{
			st[i] = true;
			if (dfs(i, t[i]))
			{
				is_ok = true;
				break;
			}
			memset(st, 0, sizeof st);
		}
		memset(st, 0, sizeof st);
		cout << (is_ok ? "YES" : "NO") << endl;
	}

	return 0;
}
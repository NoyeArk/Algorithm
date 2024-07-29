/**
 * @file 852. spfa判断负环.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-07-29
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 2010, M = 10010;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[N];
bool st[N];

bool spfa()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	queue<int> q;
	for (int i = 1; i <= n; i ++)
	{
		q.push(i);
		st[i] = true;
	}

	while (q.size())
	{
		int t = q.front(); q.pop();
		st[t] = false;

		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= n) return true;
				if (!st[j])
				{
					st[j] = true;
					q.push(j);
				}
			}
		}
	}
	return false;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while (m --)
	{
		int a, b, c; cin >> a >> b >> c;
		e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
	}

	cout << (spfa() ? "Yes" : "No");

	return 0;
}
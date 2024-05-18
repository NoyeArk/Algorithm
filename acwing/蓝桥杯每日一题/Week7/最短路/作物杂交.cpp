/**
 * @file 作物杂交.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-18
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	感觉和关键路径有关
 * ------------------------------
 * 	1.spfa，本质上是一个dp问题
 * 		1.1 状态表示：f[i][j]表示所有在i步以内可以生成作物j的最小花费时间的集合
 * 		1.2 状态计算：f[i][j] = max(w[x], w[y]) + max(f[i - 1][x], f[i - 1][y])
 * 		为什么可以使用spfa？
 * 		本质上spfa就是一个dp问题，只不过将第一维进行了优化，即只保存可以到达点j的最小时间
 * 		dist数组也就是上面的f数组
 *	2.dijkstra：本质上是一个贪心算法
 *  	取出来一个点，如果不是x，那么肯定需要集合中的另外一个点来更新它，使x最小
 */

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 2010, M = 200010;
int n, m, k, t; 
int h[N], e[M], ne[M], w[M], target[M], idx;
int dist[N];
bool st[N];
queue<int> q;

void add(int a, int b, int c)
{
	e[idx] = b, target[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void spfa()
{
	int cnt = 0;
	while (q.size())
	{
		auto x = q.front(); q.pop();
		st[x] = false;
		for (int i = h[x]; i != -1; i = ne[i])
		{
			int y = e[i], t = target[i];
			if (dist[t] > max(w[x], w[y]) + max(dist[x], dist[y]))
			{
				dist[t] = max(w[x], w[y]) + max(dist[x], dist[y]);
				if (!st[t])
				{
					q.push(t);
					st[t] = true;
				}
			}
		}
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m >> k >> t;	
	// 第i个作物的种植时间Ti
	for (int i = 1; i <= n; i ++) cin >> w[i];

	// 已拥有的种子类型
	memset(dist, 0x3f, sizeof dist);
	while (m --)
	{
		int x; cin >> x;
		dist[x] = 0;
		q.push(x);
		st[x] = true;
	}

	// 杂交方案
	while (k --)
	{
		int a, b, c; cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}

	spfa();
	
	cout << dist[t];
	return 0;
}
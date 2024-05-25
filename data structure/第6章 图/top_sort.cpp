/**
 * @file top_sort.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-25
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	先将所有入度为0的点放入队列中，然后依次取出队列中的每个点，将其指向的后继
 * 	结点的入度减一，如果减完之后入度为0，那么加入队列中
 * 	判断最后的队尾指针是否等于结点个数-1
 * 		如果等于：当前队列中的元素就是一种拓扑排序
 * 		如果不等于：不存在拓扑排序
 * 	运行时间：412ms 运行空间：3940KB
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int n, m;
int d[N];
int q[N], hh, tt = -1;
int h[N], e[N], ne[N], idx;

bool top_sort()
{
	for (int i = 1; i <= n; i ++)
		if (!d[i]) q[++ tt] = i;
	while (hh <= tt)
	{
		int t = q[hh ++];
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (-- d[j] == 0)
				q[++ tt] = j;
		}
	}
	return tt == n - 1;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while (m --)
	{
		int a, b; cin >> a >> b;
		d[b] ++;
		e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
	}

	if (top_sort())
		for (int i = 0; i <= tt; i ++)	cout << q[i] << " ";
	else cout << -1;
	return 0;
}
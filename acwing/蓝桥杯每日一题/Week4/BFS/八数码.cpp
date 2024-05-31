/**
 * @file 八数码.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-31
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	1.这种问题可以使用字符串来进行表示
 * 	2.同时一般表示距离的时候可能开一个数组，但是由于是字符串，所以可以使用
 * 	  一个unordered_map来保存对应的距离
 */

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int bfs(string st)
{
	string end = "12345678x";

	queue<string> q;
	unordered_map<string, int> dist;

	q.push(st);
	dist[st] = 0;

	while (q.size())
	{
		auto t = q.front(); q.pop();
		int d = dist[t];

		if (t == end) return d;

		int k = t.find('x');
		int x = k / 3, y = k % 3;

		for (int i = 0; i < 4; i ++)
		{
			int a = x + dx[i], b = y + dy[i];
			if (a < 0 || a > 2 || b < 0 || b > 2) continue;
			swap(t[k], t[a * 3 + b]);
			if (!dist.count(t))
			{
				dist[t] = d + 1;
				q.push(t);
			}
			swap(t[k], t[a * 3 + b]);
		}
	}
	return -1;
}

int main()
{
	string st;
	for (int i = 0; i < 9; i ++)
	{
		char c; cin >> c;
		st += c;
	}
	cout << bfs(st);
	return 0;
}
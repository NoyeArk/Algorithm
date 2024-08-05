/**
 * @file 172. 立体推箱子.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-05
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

typedef pair<int, int> PII;

const int N = 510;
int n, m;
char g[N][N];
struct Point
{
	bool two = false;
	PII p1, p2;
}

const int up = 0, down = 1, left = 2, right = 3;

vector<PII> origin;

int bfs()
{
	int res = 0;
	while (q.size())
	{
		auto t = q.front(); q.pop();
		// 判断4个方向
		
	}
	return res;
}

void work()
{
	q.clear();
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) 
		{
			cin >> g[i][j];
			if (g[i][j] == 'X') origin.push_back({i, j});
		}

	Point p;
	p.p1 = {origin[0]};
	if (origin.size() == 2) p.p2 = origin[1], p.two = true;
	queue<Point> q;
	q.push(p);

	bfs();
}

int main()
{
	while (cin >> n >> m, !n && !m)	work();
	return 0;
}
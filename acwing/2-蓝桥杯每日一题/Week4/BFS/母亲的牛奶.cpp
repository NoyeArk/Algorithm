/**
 * @file 母亲的牛奶.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-22
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 25;
int A, B, C;
bool st[N][N][N];
vector<int> ans;

struct Node
{
	int a, b, c;
};

void bfs()
{
	st[0][0][C] = true;
	queue<Node> q;
	q.push({0, 0, C});

	while (q.size())
	{
		auto it = q.front(); q.pop();
		int a = it.a, b = it.b, c = it.c;

		ans.push_back(c);
		if (a) 
		{
			// A往B倒
			int l = min(a, B - b);
			if (!st[a - l][b + l][c])
			{
				q.push({a - l, b + l, c});
				st[a - l][b + l][c] = true;
			}
			// A往C倒
			l = min(a, C - c);
			if (!st[a - l][b][c + l])
			{
				q.push({a - l, b, c + l});
				st[a - l][b][c + l] = true;
			}
		}
		if (b)
		{
			// B往A倒
			int l = min(b, A - a);
			if (!st[a + l][b - l][c])
			{
				q.push({a + l, b - l, c});
				st[a + l][b - l][c] = true;
			}
			// B往C倒
			l = min(b, C - c);
			if (!st[a][b - l][c + l])
			{
				q.push({a, b - l, c + l});
				st[a][b - l][c + l] = true;
			}
		}
		if (c)
		{
			// C往A倒
			int l = min(c, A - a);
			if (!st[a + 1][b][c - l])
			{
				q.push({a + l, b, c - l});
				st[a + 1][b][c - l] = true;
			}
			// C往B倒
			l = min(c, B - b);
			if (!st[a][b + l][c - l])
			{
				q.push({a, b + l, c - l});
				st[a][b + 1][c - l] = true;
			}
		}
	}
}

int main()
{
	cin >> A >> B >> C;

	bfs();

	sort(ans.begin(), ans.end());
	// for (auto t : ans) cout << t << " ";
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	for (auto t : ans) cout << t << " ";
	return 0;
}
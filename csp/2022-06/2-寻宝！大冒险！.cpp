/**
 * @file 2-寻宝！大冒险！.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-26
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <utility>
#include <map>
using namespace std;

typedef pair<int, int> PII;

const int N = 1010;
PII p[N];
int n, L, S;
int B[N][N];

map<pair<int, int>, int> h;

bool check(int x, int y, int i, int j)
{
	if (x > L || y > L) return false;
	if (h.find({x, y}) == h.end() && B[i][j] == 0)
		return true;
	if (h.find({x, y}) != h.end() && B[i][j] == 1)
		return true;
	return false;
}

int main()
{
	cin >> n >> L >> S;

	// 读入绿化图
	for (int i = 1; i <= n; i ++)
	{
		int x, y; cin >> x >> y;
		p[i] = {x, y};
		h[{x, y}] = true;
	}

	// 读入藏宝图
	for (int i = S; i >= 0; i --)
		for (int j = 0; j <= S; j ++)
			cin >> B[i][j];

	int ans = 0;
	// 遍历绿化图中的每个树
	for (int k = 1; k <= n; k ++)
	{
		int x = p[k].first, y = p[k].second;
		int cnt = 0;
		for (int i = 0; i <= S; i ++)
		{
			bool is_ok = true;
			for (int j = 0; j <= S; j ++)
				if (!check(x + i, y + j, i, j))
				{
					is_ok = false;
					break;
				}
				else cnt ++;
			if (!is_ok) break;
		}
		if (cnt == (S + 1) * (S + 1)) ans ++;
	}

	cout << ans;
	return 0;
}
/**
 * @file 病毒溯源.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-19
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	感觉可以用DFS来做，不用动态规划，成功！！！
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10010;
int n;
bool d[N];
int h[N], e[N], ne[N], idx;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

vector<int> cmp(vector<int>& a, vector<int>& b)
{
	for (int i = 0; i < a.size(); i ++)
		if (a[i] > b[i]) return b;
		else if (a[i] < b[i]) return a;
}

vector<int> dfs(int u)
{
	vector<int> path;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		auto res = dfs(j);
		if (res.size() > path.size()) path = res;
		else if (res.size() == path.size()) path = cmp(res, path);
	}
	path.insert(path.begin(), u);
	return path;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n;

	for (int i = 0; i < n; i ++)
	{
		int k; cin >> k;
		while (k --)
		{
			int child; cin >> child;
			add(i, child);
			d[child] = true;
		}
	}

	int r = 0;
	while (d[r]) r ++;

	auto ans = dfs(r);
	cout << ans.size() << endl;
	for (auto c : ans) cout << c << " ";

	return 0;
}
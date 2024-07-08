/**
 * @file 842. 排列数字.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-07-08
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

const int N = 10;

int n;
bool st[N];
vector<int> path;

void dfs(int u)
{
	if (u > n)
	{
		for (auto& x : path) cout << x << " ";
		cout << endl;
		return ;
	}
	for (int i = 1; i <= n; i ++)
	{
		if (st[i]) continue;
		st[i] = true, path.push_back(i);
		dfs(u + 1);
		st[i] = false, path.pop_back();
	}
}

int main()
{
	cin >> n;
	dfs(1);
	return 0;
}
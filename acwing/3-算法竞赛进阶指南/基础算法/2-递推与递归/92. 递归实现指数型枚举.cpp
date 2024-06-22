/**
 * @file 92. 递归实现指数型枚举.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-22
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	一共有2的15次方种状态 大约是32798 直接DFS枚举
 */

#include <iostream>
#include <vector>
using namespace std;

int n;

vector<int> path;

void dfs(int u)
{
	if (u > n) 
	{
		for (auto& x : path) cout << x << " ";
		cout << endl;
		return ;
	}
	// 不选第u个
	dfs(u + 1);
	// 选第u个
	path.push_back(u);
	dfs(u + 1);
	path.pop_back();
}

int main()
{
	cin >> n;
	dfs(1);
	return 0;
}
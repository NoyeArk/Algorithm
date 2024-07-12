/**
 * @file 129. 火车进栈.cpp
 * @author horiki
 * @version 0.2
 * @date 2024-07-10 2024-07-12
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	对于每一个火车j，在它要进站的时候，如果火车站中已有num个火车，可以进行一下操作：
 * 	对于任意的0<=i<=num，火车j可以在前i个火车出站后进入
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<int> path;
vector<vector<int>> ans;

void dfs(int u, stack<int> stk)
{
	if (u > n)
	{
		ans.push_back(path);
		while (stk.size()) 
		{
			ans.back().push_back(stk.top());
			stk.pop();
		}
		return ;
	}
	int m = stk.size();
	// 先把栈中的元素全部弹出
	for (int i = 1; i <= m; i ++)
		path.push_back(stk.top()), stk.pop();
	for (int i = 0; i <= m; i ++)
	{
		if (i) stk.push(path.back()), path.pop_back();
		stk.push(u);
		dfs(u + 1, stk);
		stk.pop();
		if (ans.size() >= 20) return ;
	}
}

int main()
{
	cin >> n;
	dfs(1, stack<int>());
	for (int i = 0; i < ans.size(); i ++)
	{
		for (auto& x : ans[i]) cout << x;
		cout << endl;
	}
	return 0;
}
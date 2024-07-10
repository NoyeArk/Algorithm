/**
 * @file 129. 火车进栈.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-07-10
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	对于每一个火车，在它要进站的时候，可以进行2种操作：
 * 		1.火车站中已有的火车出站，当前
 * 		2.当前火车进站
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
	for (int i = 0; i <= stk.size(); i ++)
	{
		if (i)
		{
			// 弹出栈顶
			int t = stk.top(); stk.pop();
			path.push_back(t);
		}
		stack<int> k(stk);
		k.push(u);
		dfs(u + 1, k);
		if (i) path.pop_back();
	}
}

int main()
{
	cin >> n;
	dfs(1, stack<int>());
	sort(ans.begin(), ans.end());
	for (auto& nums : ans)
	{
		for (auto& x : nums) cout << x;
		cout << endl;
	}
	return 0;
}
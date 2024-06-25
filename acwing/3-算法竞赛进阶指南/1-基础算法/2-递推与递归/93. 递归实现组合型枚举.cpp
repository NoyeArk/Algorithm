/**
 * @file 93. 递归实现组合型枚举.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-25
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	递归：每个元素可以选或不选
 * 	非递归：递归实际上就是对栈操作的过程，如果使用非递归，应该可以使用一个栈来模拟递归
 * 		什么时候入栈？
 * 		什么时候出栈？
 * 		栈中应该存放什么？	栈中应该存放的遍历顺序
 */

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> path;

void dfs(int u, int cnt)
{
	if (cnt == m)
	{
		for (auto& x : path) cout << x << " ";
		cout << endl;
		return ;
	}
	if (u > n) return ;
	// 选第u个
	path.push_back(u);
	dfs(u + 1, cnt + 1);
	path.pop_back();
	// 不选第u个
	dfs(u + 1, cnt);
}

int main()
{
	cin >> n >> m;
	dfs(1, 0);

	return 0;
}
/**
 * @file 133. 蚯蚓.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-07-15
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 100010;
int n, m, q, u, v, t;
priority_queue<int> qq;

void print_queue()
{
	cout << endl << "----" << endl;
	auto k = qq;
	while (k.size())
	{
		cout << k.top() << " ";
		k.pop();
	}
	cout << endl << "----" << endl;
}

void work1()
{
	auto k = qq; qq = priority_queue<int>();
	// 将最长的蚯蚓切成2半
	int len = k.top(); k.pop();
	qq.push(len * u / v), qq.push(len - len * u / v);
	// 其他蚯蚓长度增加q
	while (k.size())
		qq.push(k.top() + q), k.pop();
	cout << len << " ";
	// print_queue();
}

void work2()
{
	while (qq.size())
	{
		cout << qq.top() << " ";
		qq.pop();
	}
}

int main()
{
	cin >> n >> m >> q >> u >> v >> t;
	for (int i = 1; i <= n; i ++) 
	{
		int x; cin >> x;
		qq.push(x);
	}

	int cnt = m / t;
	while (cnt --) work1();
	cout << endl;

	cnt = (n + m) / t;
	while (cnt --) work2();

	return 0;
}
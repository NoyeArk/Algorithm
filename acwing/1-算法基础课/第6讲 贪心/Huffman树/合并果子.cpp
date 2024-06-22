/**
 * @file 合并果子.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-16
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	每次选择含有果子数量最少的进行合并
 * 	使用一个优先队列维护
 */

#include <iostream>
#include <queue>
using namespace std;

const int N = 10010;
int n;
priority_queue<int, vector<int>, greater<int>> q;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		int a; cin >> a;
		q.push(a);
	}

	int ans = 0;
	while (q.size() > 1)
	{
		auto a = q.top(); q.pop();
		auto b = q.top(); q.pop();
		q.push(a + b);
		ans += a + b;
	}

	cout << ans;
	return 0;
}
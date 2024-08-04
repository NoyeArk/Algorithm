/**
 * @file 5840. 封印序列.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-03
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	1.使用并查集：疯狂的馒头
 * 	倒着做，相当于每次添加一个数
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 100010;
int a[N], b[N], pre[N];

int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) 
	{
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i ++) cin >> b[i];

	int sum = 0;
	for (int i = 1; i <= n; i ++) sum += a[i];

	priority_queue<int, vector<int>, greater<int>> heap;
	heap.push(sum);

	for (int i = 1; i <= n; i ++)
	{
		int j = b[i];
		heap.push(pre[j]), heap.push(pre[])
	}

	return 0;
}
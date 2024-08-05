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
using namespace std;

typedef long long LL;

const int N = 100010;
int a[N], b[N], pre[N];
LL sum[N], ans[N];
bool st[N];

int find(int x)
{
	return pre[x] = (pre[x] == x ? x : find(pre[x]));
}

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) pre[i] = i;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) cin >> b[i];

	for (int i = n; i; i --)
	{
		int j = b[i];
		st[j] = true, sum[j] = a[j];
		if (st[j + 1]) sum[find(j + 1)] += sum[j], pre[j] = find(j + 1);
		if (st[j - 1]) sum[find(j)] += sum[j - 1], pre[j - 1] = find(j);
		ans[i - 1] = max(ans[i], sum[find(j)]);
	}

	for (int i = 1; i <= n; i ++) cout << ans[i] << endl;
	return 0;
}
/**
 * @file 三国游戏.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-03
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	面对这种问题，不知道怎么转换
 * 		按照每一个国家在每一次加兵的数量与其他国家加兵的和做差，并进行排序
 * 		从大到小进行遍历，求出diff数组的前缀和，如果这个前缀和小于0
 * 		那么当前i - 1就是这个国家能获胜的最大事件数
 * 	通过了9个数据，为什么最后一个过不了，原因因为1e9要开LL
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 100010;
LL a[N], b[N], c[N];
LL sum[N], diff[N];

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) cin >> b[i];
	for (int i = 1; i <= n; i ++) cin >> c[i];

	for (int i = 1; i <= n; i ++) 
		sum[i] = a[i] + b[i] + c[i];
	
	// 判断A是否能够获胜
	for (int i = 1; i <= n; i ++)
	{
		LL rest = sum[i] - a[i];
		diff[i] = a[i] - rest;
	}

	sort(diff + 1, diff + 1 + n, greater<int>());

	LL ans1 = 0, pre = 0;
	// 判断diff的前多少项和为正数
	for (int i = 1; i <= n; i ++)
	{
		pre += diff[i];
		if (pre <= 0) break;
		else ans1 ++;
	}


	// 判断B是否能够获胜
	for (int i = 1; i <= n; i ++)
	{
		LL rest = sum[i] - b[i];
		diff[i] = b[i] - rest;
	}

	sort(diff + 1, diff + 1 + n, greater<int>());

	LL ans2 = 0;
	pre = 0;
	// 判断diff的前多少项和为正数
	for (int i = 1; i <= n; i ++)
	{
		pre += diff[i];
		if (pre <= 0) break;
		else ans2 ++;
	}


	// 判断C是否能够获胜
	for (int i = 1; i <= n; i ++)
	{
		LL rest = sum[i] - c[i];
		diff[i] = c[i] - rest;
	}

	sort(diff + 1, diff + 1 + n, greater<int>());

	LL ans3 = 0;
	pre = 0;
	// 判断diff的前多少项和为正数
	for (int i = 1; i <= n; i ++)
	{
		pre += diff[i];
		if (pre <= 0) break;
		else ans3 ++;
	}

	if (!ans1 && !ans2 && !ans3) cout << -1;
	else cout << max(ans1, max(ans2, ans3));

	return 0;
}
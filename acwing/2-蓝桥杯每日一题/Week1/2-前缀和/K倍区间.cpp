/**
 * @file K倍区间.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-14
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	找一个区间的和是k的倍数，等价于区间的左端点和区间右端点的前缀和对k取模的结果相同
 */

#include <iostream>
using namespace std;

typedef long long LL;

const int N = 100010;
LL pre[N], cnt[N];

int main()
{
	int n, k; cin >> n >> k;

	LL ans = 0;
	cnt[0] = 1;
	for (int i = 1; i <= n; i ++) 
	{
		cin >> pre[i];
		pre[i] += pre[i - 1];
		ans += cnt[pre[i] % k];
		cnt[pre[i] % k] ++;
	}

	cout << ans;
	return 0;
}
/**
 * @file 技能升级.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-18
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	直接算会超时啊
 */

#include <iostream>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
int n, m;
// int a[N], b[N];
PII a[N], tmp[N];

bool cmp(PII a, PII b)
{
	return a.first > b.first;
}

// int main()
// {
// 	cin >> n >> m;
// 	for (int i = 1; i <= n; i ++) cin >> a[i].first >> a[i].second;
// 	int ans = 0;
// 	while (m --)
// 	{
// 		sort(a + 1, a + 1 + n, cmp);
// 		ans += a[1].first;
// 		a[1].first = max(0, a[1].first - a[1].second);
// 	}
// 	cout << ans;
// 	return 0;
// }

bool check(int mid)
{
	// 是否可以提高mid个攻击力
	memcpy(tmp, a, sizeof tmp);
	int res = 0;
	for (int i = 1; i <= m; i ++)
	{
		sort(tmp + 1, tmp + 1 + n, cmp);
		res += tmp[1].first;
		if (res >= mid) return true;
		tmp[1].first = max(0, tmp[1].first - tmp[1].second);
	}
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i].first >> a[i].second;

	int l = 0, r = 1e9;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}

	cout << r;
	return 0;
}
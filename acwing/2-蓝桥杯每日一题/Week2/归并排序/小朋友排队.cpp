/**
 * @file 小朋友排队.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-07
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	使用归并排序，只需要处理中间部分，采用分治的思想
 * 	时间复杂度：O(nlogn)
 * 	空间复杂度：O(2n)
 */

#include <iostream>
#include <utility>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010;
PII h[N], tmp[N];
int cnt[N];

LL merge_sort(int l, int r)
{
	if (l >= r) return 0;

	int mid = l + r >> 1;
	LL res = merge_sort(l, mid) + merge_sort(mid + 1, r);

	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r)
		if (h[i] <= h[j]) 
		{
			cnt[h[i].y] += j - mid - 1;
			tmp[++ k] = h[i ++];
		}
		else
		{
			// h[i, mid] 均大于 h[j]
			cnt[h[j].y] += mid - i + 1;
			tmp[++ k] = h[j ++];
		}
	
	while (i <= mid) 
	{
		cnt[h[i].y] += j - mid - 1;
		tmp[++ k] = h[i ++];
	}
	while (j <= r) tmp[++ k] = h[j ++];

	for (i = 1, j = l; i <= k; i ++, j ++) h[j] = tmp[i];
	return res;
}

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) 
	{
		cin >> h[i].x;
		h[i].y = i;
	}
	merge_sort(1, n);

	LL ans = 0;
	for (int i = 1; i <= n; i ++)
		ans += (LL)(1 + cnt[i]) * cnt[i] / 2;

	cout << ans;
	return 0;
}
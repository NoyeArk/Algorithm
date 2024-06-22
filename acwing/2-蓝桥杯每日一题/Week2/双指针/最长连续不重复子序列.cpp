/**
 * @file 最长连续不重复子序列.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-24
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	双指针：用一个cnt数组表示区间[l, r]内每个数字出现的次数
 */

#include <iostream>
using namespace std;

const int N = 100010;
int a[N], cnt[N];

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];

	int ans = 0;
	int l = 1, r = 1;
	while (r <= n)
	{
		// r向右移动
		while (!cnt[a[r]] && r <= n) cnt[a[r ++]] ++;
		// 更新答案
		ans = max(ans, r - l);
		// l向右移动
		cnt[a[l ++]] --;
	}

	cout << ans;
	return 0;
}
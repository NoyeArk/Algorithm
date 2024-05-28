/**
 * @file 壁画.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-28
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	找区间长度为n / 2的最大区间和
 */

#include <iostream>
#include <cmath>
using namespace std;

const int N = 5000010;
char s[N];
int pre[N];

int main()
{
	int t; cin >> t;
	for (int i = 1; i <= t; i ++)
	{
		int n; cin >> n >> s + 1;
		int ans = 0, len = n & 1 ? n / 2 + 1 : n / 2;
		for (int j = 1; j <= n; j ++)
		{
			pre[j] = pre[j - 1] + s[j] - '0';
			if (j >= len) ans = max(ans, pre[j] - pre[j - len]);
		}
		printf("Case #%d: %d\n", i, ans);
	}

	return 0;
}
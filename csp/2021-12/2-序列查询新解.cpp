/**
 * @file 2-序列查询新解.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-29
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int a[N];

int binary_search(int x)
{
	int l = 0, r = n;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (a[mid] <= x) l = mid;
		else r = mid - 1;
	}
	return r;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];

	long long ans = 0;
	int id = -1, rr = m / (n + 1);
	for (int i = 0; i < m; i ++)
	{
		if (id == -1) id = binary_search(i);
		else 
			while (id <= n && a[id] <= i) id ++;
		if (id > n || a[id] > i) id --;
		ans += abs(i / rr - id);
	}

	cout << ans;
	return 0;
}
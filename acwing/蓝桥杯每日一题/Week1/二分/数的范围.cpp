/**
 * @file 数的范围.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-25
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 1000010;
int a[N];

int main()
{
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	while (q --)
	{
		int k; cin >> k;

		int l = 1, r = n;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (a[mid] < k) l = mid + 1;
			else r = mid;
		}

		if (a[l] != k)
		{
			cout << -1 << " " << -1 << endl;
			continue;
		}
		cout << r - 1 << " ";
		l = 1, r = n;
		while (l < r)
		{
			int mid = l + r + 1 >> 1;
			if (a[mid] > k) r = mid - 1;
			else l = mid;
		}
		cout << r - 1 << endl;
	}

	return 0;
}
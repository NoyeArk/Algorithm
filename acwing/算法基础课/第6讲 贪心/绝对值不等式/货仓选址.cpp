/**
 * @file 货仓选址.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-16
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	放在中位数一定是最小值
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int n;
int a[N];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];

	sort(a, a + n);

	int ans = 0;
	for (int i = 0; i < n; i ++) 
		ans += abs(a[i] - a[n / 2]);

	cout << ans;
	return 0;
}

// 1 2 3 4 5 6 7 8 9
// 1 1 0 0 0 1 0 0 1
// 0 0 0 0 1 0 0 0 0 = 4 + 3 + 1 + 4 = 12
// 0 0 0 1 0 0 0 0 0 = 3 + 2 + 2 + 5 = 12
// 0 1 0 0 0 0 0 0 0 = 1 + 0 + 4 + 7 = 12
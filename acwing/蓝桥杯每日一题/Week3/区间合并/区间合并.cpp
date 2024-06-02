/**
 * @file 区间合并.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-02
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	合并所有有交集的区间
 */

#include <iostream>
#include <utility>
#include <algorithm>

#define x first
#define y second
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
PII a[N];


int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i].x >> a[i].y;

	sort(a + 1, a + 1 + n);

	int ed = -2e9, ans = 0;
	for (int i = 1; i <= n; i ++)
	{
		if (ed < a[i].x)
			ans ++;
		ed = max(ed, a[i].y);
	}

	cout << ans;
	return 0;
}
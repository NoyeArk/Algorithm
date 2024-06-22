/**
 * @file 区间选点.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-30
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	将区间按照左端点从小到大排序
 * 	如果当前最大区间的右端点小于下一个区间的左端点
 * 	结果 + 1 并且更新当前的右端点
 * ---------------------------------------------
 * 	应该按照右端点排序 引入每次更新右端点 如果按照左端点排序的话 右端点是无序的
 */

#include <iostream>
#include <utility>
#include <algorithm>

#define y first
#define x second
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
PII a[N];

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i].x >> a[i].y;
	sort(a + 1, a + 1 + n);

	int mx = -2e9, ans = 0;
	for (int i = 1; i <= n; i ++)
		if (mx < a[i].x) mx = a[i].y, ans ++;

	cout << ans;
	return 0;
}
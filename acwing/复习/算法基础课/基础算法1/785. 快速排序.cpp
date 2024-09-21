/**
 * @file 785. 快速排序.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-07-10
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int a[N];

void quick_sort(int l, int r)
{
	if (l >= r) return ;
	int k = a[l + r >> 1], i = l - 1, j = r + 1;
	while (i < j)
	{
		do i ++; while (a[i] < k);
		do j --; while (a[j] > k);
		if (i < j) swap(a[i], a[j]);
	}
	quick_sort(l, j);
	quick_sort(j + 1, r);
}

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];

	quick_sort(1, n);

	for (int i = 1; i <= n; i ++) cout << a[i] << " ";
	return 0;
}
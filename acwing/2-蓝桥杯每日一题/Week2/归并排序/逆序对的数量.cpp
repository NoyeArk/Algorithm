/**
 * @file 逆序对的数量.cpp
 * @author horiki
 * @version 0.2
 * @date 2024-05-25 2024-06-07
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	将序列从中间分开，逆序对则分为三类：
 * 		1.两个元素都在左边
 * 		2.两个元素都在右边
 * 		3.两个元素一左一右
 */

#include <iostream>
using namespace std;

typedef long long LL;

const int N = 100010;
int a[N], tmp[N];

LL merge_sort(int l, int r)
{
	if (l >= r) return 0;
	
	int mid = l + r >> 1;
	LL res = merge_sort(l, mid) + merge_sort(mid + 1, r);

	int k = 1, i = l, j = mid + 1;
	while (i <= mid && j <= r)
		if (a[i] <= a[j]) tmp[k ++] = a[i ++];
		else
		{
			res += mid - i + 1;
			tmp[k ++] = a[j ++];
		}
	while (i <= mid) tmp[k ++] = a[i ++];
	while (j <= r) tmp[k ++] = a[j ++];
	for (i = l, j = 1; i <= r; i ++, j ++) a[i] = tmp[j];

	return res;
}

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	cout << merge_sort(1, n);
	return 0;	
}
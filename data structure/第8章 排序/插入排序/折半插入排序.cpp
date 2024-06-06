/**
 * @file 折半插入排序.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-21
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	稳定的排序算法
 * 	时间复杂度：O(n²) 
 * 		最好：O(n)
 * 		最坏：O(n²)
 * 	空间复杂度：O(1)
 */

#include <iostream>
using namespace std;

const int N = 100010;
int n;
int a[N];

void halfway_insert_sort()
{
	for (int i = 2; i <= n; i ++)
	{
		int val = a[i];
		// 需要找到第一个大于a[i]的数的位置
		int l = 1, r = i;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (a[mid] <= val) l = mid + 1;
			else r = mid;
		}
		// 将[r, i - 1]之间的数移动到[r + 1, i]
		for (int j = i; j > r; j --)
			a[j] = a[j - 1];
		a[r] = val;
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];

	halfway_insert_sort();

	for (int i = 1; i <= n; i ++) cout << a[i] << " ";
	return 0;
}
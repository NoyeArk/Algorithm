/**
 * @file 插入排序.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-19
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int n;
int a[N];

void insert_sort()
{
	// 当前要排序的前i个元素
	for (int i = 2; i <= n; i ++)
	{
		int val = a[i], j;
		// 找到合适的位置
		for (j = i; j > 1 && val < a[j - 1]; j --)
			a[j] = a[j - 1];
		a[j] = val;
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];

	insert_sort();

	for (int i = 1; i <= n; i ++) cout << a[i] << " ";
	return 0;
}
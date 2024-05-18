/**
 * @file 冒泡排序.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-18
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

void bubble_sort()
{
	for (int i = n; i > 1; i --)
		for (int j = 1; j < i; j ++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];

	bubble_sort();

	for (int i = 1; i <= n; i ++) cout << a[i] << " ";
	return 0;
}
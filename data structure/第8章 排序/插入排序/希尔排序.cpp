/**
 * @file 希尔排序.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-21
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

void shell_sort()
{
	for (int gap = n / 2; gap; gap /= 2)
	{
		for (int i = gap + 1; gap <= n; i ++)
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];

	shell_sort();

	for (int i = 1; i <= n; i ++) cout << a[i] << " ";
	return 0;
}
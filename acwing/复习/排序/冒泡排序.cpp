/**
 * @file 冒泡排序.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-07
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

void sort()
{
    for (int i = 1; i < n; i ++)
        for (int j = i + 1; j <= n; j ++)
            if (a[i] > a[j]) swap(a[i], a[j]);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];

    sort();

	for (int i = 1; i <= n; i ++) cout << a[i] << " ";
	return 0;
}
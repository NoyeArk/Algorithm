/**
 * @file 插入排序.cpp
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
    for (int i = 2; i <= n; i ++)
    {
        int val = a[i], j;
        for (j = i; j > 1 && a[j - 1] > val; j --)
            a[j] = a[j - 1];
        a[j] = val;
    }
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];

    sort();

	for (int i = 1; i <= n; i ++) cout << a[i] << " ";
	return 0;
}
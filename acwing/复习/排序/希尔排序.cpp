/**
 * @file 希尔排序.cpp
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

void shell_sort()
{
    for (int k = n / 2; k; k /= 2)
        for (int i = k + 1; i <= n; i ++)
            if (a[i] < a[i - k])
            {
                int val = a[i], j;
                for (j = i; j > k && val < a[j - k]; j -= k)
                    a[j] = a[j - k];
                a[j] = val;
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
/**
 * @file 2-何以包邮.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-20
 * @copyright Copyright (c) 2024
 * 
 * @brief
 * 	
 * 	从中选择几本书，使得这几本书的总价值在背包容量为sum-x的情况下，总和越大越好
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 35, M = 300010;
int a[N], f[M];
int n, x; 

int main()
{
	cin >> n >> x;
	int sum = 0;
	for (int i = 1; i <= n; i ++) 
	{
		cin >> a[i];
		sum += a[i];
	}

	int m = sum - x;
	for (int i = 1; i <= n; i ++)
		for (int j = m; j >= a[i]; j --)
			f[j] = max(f[j], f[j - a[i]] + a[i]);

	cout << sum - f[m];
	return 0;
}
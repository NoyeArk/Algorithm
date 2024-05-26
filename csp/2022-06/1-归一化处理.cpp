/**
 * @file 1-归一化处理.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-26
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <cmath>
using namespace std;

const int N = 1010;
double a[N];

int main()
{
	int n; cin >> n;

	int sum = 0;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		sum += a[i];
	}

	double avg = (double)sum / n;
	double d = 0;
	// 计算方差
	for (int i = 1; i <= n; i ++)
		d += pow(a[i] - avg, 2);

	d = sqrt(d / n);

	for (int i = 1; i <= n; i ++)
		a[i] = (a[i] - avg) / d;

	for (int i = 1; i <= n; i ++) cout << a[i] << endl;

	return 0;
}
/**
 * @file 空调.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-20
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int p[N], t[N];
int diff[N];

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> p[i];
		diff[i] = p[i] - p[i - 1];
	}

	int neg = 0, pos = 0;

	for (int i = 1; i <= n; i ++)
	{
		cin >> t[i];
		int tmp = t[i] - t[i - 1] - diff[i];
		if (tmp < 0) neg += tmp;
		else if (tmp > 0) pos += tmp;
	}

	cout << max(abs(neg), pos);
	return 0;
}
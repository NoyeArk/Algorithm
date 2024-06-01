/**
 * @file 2-模方程.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-01
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	x只能在a - b的约数中找，可以使用试除法求所有约数
 * 	同时只能找大于b的约数
 */

#include <iostream>
using namespace std;

int main()
{
	int a, b; cin >> a >> b;
	int n = a - b;

	int ans = 0;
	for (int i = 2; i <= n / i; i ++)
		if (n % i == 0)
		{
			if (i > b) ans ++;
			if (i != n / i && n / i > b)
				ans ++; 
		}

	if (a == b) cout << "infinity";
	else cout << ans;
	return 0;
}
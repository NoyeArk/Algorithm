/**
 * @file 90. 64位整数乘法.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-22
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	使用long long只能过2个数据，应该使用高精度乘法？
 * 	可以不使用高精度
 */

#include <iostream>
using namespace std;

typedef unsigned long long ULL;

int main()
{
	ULL a, b, p; cin >> a >> b >> p;
	
	ULL ans = 0;
	while (b)
	{
		if (b & 1) ans = (ans + a) % p;
		b >>= 1;
		a = a * 2 % p;
	}

	cout << ans;
	return 0;
}
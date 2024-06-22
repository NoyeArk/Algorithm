/**
 * @file 最大公约数.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-03
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	使用辗转相除法
 */

#include <iostream>
using namespace std;

typedef long long LL;

int gcd(LL a, LL b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int n; cin >> n;
	while (n --)
	{
		LL a, b; cin >> a >> b;
		cout << gcd(a, b) << endl;
	}

	return 0;
}
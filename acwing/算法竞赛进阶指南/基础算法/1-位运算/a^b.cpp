/**
 * @file a^b.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-13
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

typedef long long LL;

int p;

int qmi(int a, int k)
{
	int res = 1;
	while (k)
	{
		if (k & 1) res = (LL)res * a % p;
		k >>= 1;
		a = (LL)a * a % p;
	}
	return res;
}

int main()
{
	int a, b; cin >> a >> b >> p;
	cout << qmi(a, b) % p;
	return 0;
}
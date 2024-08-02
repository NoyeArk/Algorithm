/**
 * @file 866. 试除法判定质数.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-02
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

bool is_prime(int n)
{
	if (n < 2) return false;
	for (int i = 2; i <= n / i; i ++)
		if (n % i == 0) return false;
	return true;
}

int main()
{
	int n; cin >> n;
	while (n --)
	{
		int x; cin >> x;
		cout << (is_prime(x) ? "Yes" : "No") << endl;
	}

	return 0;
}
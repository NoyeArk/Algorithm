/**
 * @file 约数的个数.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-06
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

int work(int x)
{
	int res = 0;
	for (int i = 1; i <= x / i; i ++)
		if (x % i == 0)
		{
			res ++;
			if (x / i != i) res ++;
		}
	return res;
}

int main()
{
	int n; cin >> n;
	while (n --)
	{
		int x; cin >> x;
		cout << work(x) << endl;
	}

	return 0;
}
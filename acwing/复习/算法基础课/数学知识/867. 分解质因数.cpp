/**
 * @file 867. 分解质因数.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-07-18
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	while (n --)
	{
		int x; cin >> x;
		for (int i = 2; i <= x / i; i ++)
		{
			int cnt = 0;
			if (x % i == 0)
			{
				while (x % i == 0) 
					cnt ++, x /= i;
				cout << i << " " << cnt << endl;
			}
		}
		if (x > 1) cout << x << " 1" << endl;
		cout << endl;
	}

	return 0;
}
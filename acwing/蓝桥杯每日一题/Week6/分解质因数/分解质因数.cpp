/**
 * @file 分解质因数.cpp
 * @author horiki
 * @version 0.2
 * @date 2024-05-18 2024-05-19
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	遍历2~x / i，判断是否能够整除，如果可以，一直除尽，输出结果
 */

#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n; 
	while (n --)
	{
		int a; cin >> a;
		for (int i = 2; i <= a / i; i ++)
		{
			if (a % i == 0)
			{
				int cnt = 0;
				while (a % i == 0)
					cnt ++, a /= i;
				cout << i << " " << cnt << endl;
			}
		}
		if (a > 1) cout << a << " " << 1 << endl;
		cout << endl;
	}

	return 0;
}
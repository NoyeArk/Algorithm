/**
 * @file 分解质因数.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-18
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	遍历2~x / i，判断是否能够整除，如果可以，一直除尽，输出结果
 */

#include <iostream>
using namespace std;

void work(int x)
{
	for (int i = 2; i <= x / i; i ++)
	{
		int cnt = 0;
		if (x % i == 0)
		{
			while (x % i == 0)
				x /= i, cnt ++;
			cout << i << " " << cnt << endl;
		}
	}
	if (x > 1) cout << x << " " << 1 << endl;
	cout << endl;
}

int main()
{
	int n; cin >> n;
	while (n --)
	{
		int x; cin >> x;
		work(x);
	}

	return 0;
}
/**
 * @file 最大公约数.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-01
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	欧拉函数，1~n中与n互质的数的个数
 * 	遇到问题要学会转化，很多问题如果直接求解的话很难，
 * 	但是将数学公式进行转换之后就会简单很多
 */

#include <iostream>
using namespace std;

typedef long long LL;

LL gcd(LL a, LL b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int t; cin >> t;
	while (t --)
	{
		LL a, m; cin >> a >> m;
		auto d = gcd(m, a);
		LL n = m / d, ans = n;
		// 分解质因数
		for (LL i = 2; i <= n / i; i ++)
		{
			if (n % i == 0)
			{
				ans = ans / i * (i - 1);
				while (n % i == 0) n /= i;
			}
		}
		if (n > 1) ans = ans / n * (n - 1);
		cout << ans << endl;
	}

	return 0;
}
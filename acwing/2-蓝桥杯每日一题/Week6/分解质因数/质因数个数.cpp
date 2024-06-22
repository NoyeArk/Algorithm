/**
 * @file 质因数个数.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-31
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	求解有多少个质数是n的约数
 * 	唯一分解定理:
 * 		如果一个大于1的自然数N，N不为质数，那么N可以唯一分解为有限个质数的乘积
 *  注意n的范围最大是10^16
 * 	---------------------------
 * 	为什么对i用int会超时，但是用LL不会超时
 */

#include <iostream>
using namespace std;

typedef long long LL;

int main()
{
	LL n; cin >> n;

	int ans = 0;
	for (LL i = 2; i <= n / i; i ++)
	{
		if (n % i == 0)
		{
			ans ++;
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1) ans ++;

	cout << ans;
	return 0;
}
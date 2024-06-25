/**
 * @file 5579. 增加模数.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-13
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	O(T*H*20)=4500000*20=90000000，相当于9千万的计算量
 * 	需要对输入和输出进行优化，IO开销过大
 * 	运行时间：2969ms	运行空间：69592KB
 */

#include <iostream>
using namespace std;

typedef long long LL;

int qmi(int a, int k, int p)
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
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t --)
	{
		int p, n; cin >> p >> n;

		int ans = 0;
		while (n --)
		{
			int a, b; cin >> a >> b;
			ans = (ans + qmi(a, b, p)) % p;
		}
		cout << ans << endl;
	}

	return 0;
}
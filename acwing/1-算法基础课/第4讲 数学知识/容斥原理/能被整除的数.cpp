/**
 * @file 能被整除的数.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-17
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	容斥原理：
 * 	|A∪B∪C| = |A| + |B| + |C| - |A ∩ B| - |A ∩ C| - |B ∩ C| + |A ∩ B ∩ C|
 * 	奇数的加，偶数的减
 * 	1~n中p的倍数的个数，n / p向下取整
 */

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 20;
int n, m;
int p[N];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i ++) cin >> p[i];

	int res = 0;
	for (int i = 1; i < 1 << m; i ++)
	{
		int t = 1, cnt = 0;
		for (int j = 0; j < m; j ++)
			if (i >> j & 1) 
			{
				cnt ++;
				if ((LL) t * p[j] > n)
				{
					t = -1;
					break;
				}
				t *= p[j];
			}
		
		if (t != -1) 
		{
			if (cnt % 2) res += n / t;
			else res -= n / t;
		}
	}

	cout << res;
	return 0;
}
/**
 * @file 公约数.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-01
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	先求出两个数所有的公约数，然后进行使用二分进行查询
 * 	如何求出两个数所有的公约数？
 * 		求出两个数的最大公约数，对这个最大公约数求所有约数
 * 	时间复杂度：O(qlogn) + O(logn) + O(sqrt(n))
 * 		计算最大公约数：logn
 * 		计算约数：sqrt(n)
 * 		二分：logn
 * 	
 * 	运行时间：230ms 运行空间：604KB
 * 	使用scanf和printf之后的时间一下子变成了53ms，以后还是不用cout和cin了
 */

#include <iostream>
#include <vector>
#include <algorithm>

const int N = 100010;
int q[N], cnt = 0;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

vector<int> get_divisors(int x, int y)
{
	int d = gcd(x, y);
	vector<int> res;
	for (int i = 1; i <= d / i; i ++)
	{
		if (d % i == 0)
		{
			res.push_back(i);
			if (i != d / i) res.push_back(d / i);
		}
	}
	sort(res.begin(), res.end());
	return res;
}

void init_divisors(int x, int y)
{
	int d = gcd(y, x);
	for (int i = 1; i <= d / i; i ++)
	{
		if (d % i == 0)
		{
			q[++ cnt] = i;
			if (i != d / i) q[++ cnt] = d / i;
		}
	}
	sort(q + 1, q + 1 + cnt);
}

int main()
{
	int a, b; scanf("%d%d", &a, &b);
	int t; cin >> t;

	init_divisors(a, b);
	while (t --)
	{
		int i, j; scanf("%d%d", &i, &j);

		int l = 1, r = cnt;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (q[mid] <= j) l = mid;
            else r = mid - 1;
        }
		if (i <= q[r] && q[r] <= j) printf("%d\n", q[r]);
		else printf("-1\n");
	}
	return 0;
}
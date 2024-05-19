/**
 * @file 求组合数I.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-19
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	1w组测试数据，1<=b<=a<=2000 ——> 递推 O(N²)
 *  1w组测试数据，1<=b<=a<=10^5 ——> 预处理出来逆元，使用快速幂 O(NlogN)
 *  20组测试数据，1<=b<=a<=10^18 ——> 预处理出来逆元，使用快速幂 O()
 * 
 * 	题目中是10000组测试数据，并且a和b的大小为2000，可以使用O(n²)，递推的方法
 * 	可以考虑选不选其中的一个元素来推导递推公式
 * 	递推公式：C(a, b) = C(a - 1, b - 1) + C(a - 1, b)
 */

#include <iostream>
using namespace std;

const int N = 2010, mod = 1e9 + 7;
int c[N][N];

// 预处理出来所有数据
void init()
{
	for (int i = 0; i < N; i ++)
		for (int j = 0; j <= i; j ++)
			if (!j) c[i][j] = 1;
			else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
}

int main()
{
	init();
	int n; cin >> n;
	while (n --)
	{
		int a, b; cin >> a >> b;
		// 直接使用O(1)的查询进行输出答案
		cout << c[a][b] << endl;
	}
	return 0;
}
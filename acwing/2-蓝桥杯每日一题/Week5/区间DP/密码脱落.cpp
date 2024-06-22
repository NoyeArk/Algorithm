/**
 * @file 密码脱落.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-26
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	也就是说在字符串中最少添加多少个字符，可以变成镜像串
 *  1.状态表示	
 * 		f[i][j]表示将字符串[i, j]变成镜像串的最小操作次数
 * 	2.状态计算
 * 		看区间端点i和j
 * 		如果s[i] == s[j]：那么f[i][j] = f[i + 1][j - 1]
 * 		如果s[i] != s[j]：
 * 			2.1 [i, j - 1]进行匹配，在i的位置增加一个
 * 			2.2 [i + 1, j]进行匹配，在j的位置增加一个
 * 			2.3 [i + 1, j - 1]进行匹配，i和j的位置各增加一个
 * 			上述三者取最小值
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010;
char s[N];
int f[N][N];

int main()
{
	cin >> s + 1;
	int n = strlen(s + 1);
	for (int k = 2; k <= n; k ++)
		for (int i = 1; i + k - 1 <= n; i ++)
		{
			int j = i + k - 1;
			if (s[i] == s[j]) f[i][j] = f[i + 1][j - 1];
			else 
			{
				f[i][j] = min(f[i + 1][j] + 1, f[i][j - 1] + 1);
				f[i][j] = min(f[i][j], f[i + 1][j - 1] + 2);
			}
		}

	cout << f[1][n];
	return 0;
}
/**
 * @file 松散子序列.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-25
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	1.状态表示：f[i]表示以前i个字符的松散子序列的最大价值
 * 	2.状态计算：
 * 		选第i个字符   f[i] = f[i - 2] + s[i] - 'a' + 1
 * 		不选第i个字符 f[i] = f[i - 1]
 *	运行时间：374ms  运行空间：6249KB
 */

#include <iostream>
using namespace std;

const int N = 1000010;
int f[N];

int main()
{
	string s; cin >> s;

	f[0] = s[0] - 'a' + 1;
	for (int i = 1; i < s.size(); i ++)
		f[i] = max(f[i - 1], f[i - 2] + s[i] - 'a' + 1);

	cout << f[s.size() - 1];
	return 0;
}

// -----------------------滚动数组---------------------------
// 运行时间：335ms  运行空间：3296KB
#include <iostream>
using namespace std;

int main()
{
	string s; cin >> s;
	s = " " + s;

	int f0 = 0, f1 = s[1] - 'a' + 1;
	for (int i = 2; i <= s.size(); i ++)
	{
		int f2 = max(f1, f0 + s[i] - 'a' + 1);
		f0 = f1;
		f1 = f2;
	}

	cout << f1;
	return 0;
}
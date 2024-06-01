/**
 * @file 2-继续xxx定律.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-01
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	xxx定律：对于一个数n，
 * 		如果是偶数，就把n砍掉一半；
 * 		如果是奇数，把n变成 3 * n + 1 后砍掉一半，直到该数变为1为止。
 * 	所谓关键数，就是不会出现在输入数组a[i]的其他n-1个数字的覆盖数中
 * 
 * 	求出所有数的路径，如果一个数出现在这个路径里面，那么就不是关键数
 * 
 * 	题目链接：
 * 	https://www.nowcoder.com/questionTerminal/9cc1055241c547269f58fa8b009e335d?answerType=1&f=discussion
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

const int N = 510, M = 100010;
int a[N];
int cnt[M];

void calu(int x)
{
	while (x != 1)
	{
		if (x & 1) x = (x * 3 + 1) / 2;
		else x >>= 1;
		cnt[x] ++;
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		memset(cnt, 0, sizeof cnt);
		for (int i = 1; i <= n; i ++)
		{
			cin >> a[i];
			calu(a[i]);
		}

		for (int i = n; i >= 1; i --)
			if (!cnt[a[i]]) cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}
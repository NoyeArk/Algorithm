/**
 * @file 回文日期.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-31
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	1.暴力做法会超时
 * 	2.肯定有很多日期不合法的日子，那种直接不用判断
 * 	------------------------------------------
 * 	直接构造回文数
 */

#include <iostream>
using namespace std;

const int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int y)
{
	return y % 4 == 0 && y % 100 || y % 400 == 0;
}

bool check(int date)
{
	int y = date / 10000, m = date / 100 % 100, d = date % 100;

	if (d <= 0 || d > months[m] + (m == 2 ? is_leap(y) : 0))
		return false;
	return 1 <= m && m <= 12;
}

int main()
{
	int a, b; cin >> a >> b;

	int ans = 0;
	for (int i = 1000; i < 10000; i ++)
	{
		int x = i, r = i;
		for (int j = 0; j < 4; j ++)
			r = r * 10 + x % 10, x /= 10;
		if (a <= r && r <= b && check(r))
			ans ++;
	}

	cout << ans;
	return 0;
}
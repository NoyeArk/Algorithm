/**
 * @file 日期差值.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-26
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	模板题 背下来
 */

#include <iostream>
using namespace std;

const int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap(int year)
{
	if (year % 4 == 0 && year % 100 || year % 400 == 0) return 1;
	else return 0;
}

int get_days(int y, int m)
{
	if (m == 2) return 28 + is_leap(y);
	return months[m];
}

int calc(int y, int m, int d)
{
	int res = 0;
	for (int i = 1; i < y; i ++)
		res += 365 + is_leap(i);
	for (int i = 1; i < m; i ++)
		res += get_days(y, i);
	return res + d;
}

int main()
{
	int y1, m1, d1, y2, m2, d2;
	while (~scanf("%04d%02d%02d\n%04d%02d%02d", &y1, &m1, &d1, &y2, &m2, &d2))
		cout << abs(calc(y1, m1, d1) - calc(y2, m2, d2)) + 1 << endl;
	return 0;
}
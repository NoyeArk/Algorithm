/**
 * @file 日期问题.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-26
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	运行时间：45ms 运行空间：216KB
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

vector<string> ans;

int is_leap(int y)
{
	return (y % 4 == 0 && y % 100 || y % 400 == 0);
}

bool judge(int y, int m, int d)
{
	y += (y >= 60 ? 1900 : 2000);

	if (m < 1 || m > 12) return false;

	if (m == 2) return d <= 28 + is_leap(y) && d > 0;
	return d <= months[m] && d > 0;
}

string cat(int y, int m, int d)
{
	string res = (y >= 60 ? to_string(1900 + y) : to_string(2000 + y));
	res += "-" + (m < 10 ? "0" + to_string(m) : to_string(m));
	res += "-" + (d < 10 ? "0" + to_string(d) : to_string(d));
	return res;
}

int main()
{
	char c; int x, y, z;
	scanf("%02d%c%02d%c%02d", &x, &c, &y, &c, &z);

	if (judge(x, y, z)) ans.push_back(cat(x, y, z));
	if (judge(z, x, y)) ans.push_back(cat(z, x, y));
	if (judge(z, y, x)) ans.push_back(cat(z, y, x));

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (auto s : ans) cout << s << endl;
	return 0;
}
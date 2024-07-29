/**
 * @file D. Binary Cut.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-07-29
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

bool find_01;

int get1(string s, int i)
{
	if (find_01)
	{
		while (i < s.size())
			if (s[i] != '0') return i;
			else i ++;
		return i;
	}

	// 以0开始
	bool have_one = false;
	while (i < s.size())
	{
		if (s[i] == '0' && have_one) return i;
		else if (s[i] == '0' && !have_one) find_01 = true;
		else if (s[i] == '1') have_one = true;
		i ++;
	}
	return i;
}

int get2(string s, int i)
{
	while (i < s.size())
		if (s[i] != '1') return i;
		else i ++;
	return i;
}

void work()
{
	find_01 = false;
	string s; cin >> s;
	int i = 0, ans = 0;
	while (i < s.size())
	{
		i = s[i] == '0' ? get1(s, i) : get2(s, i);
		ans ++;
	}
	cout << ans << endl;
}

int main()
{
	int t; cin >> t;
	while (t --) work();

	return 0;
}
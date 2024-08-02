/**
 * @file 137. 雪花雪花雪花.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-02
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	找出每个雪花的最小表示，然后把这个最小表示存到map中，之后实现O(1)的查询
 */

#include <iostream>
#include <unordered_map>
using namespace std;

string a[10];
unordered_map<string, bool> mp;

string work(int i)
{
	string s1, s2;
	int cnt = 0, j = i;
	while (++ cnt <= 6)
	{
		s1 += a[i], s2 += a[j];
		i = (i + 1) % 6, j = j == 0 ? 5 : j - 1;
	}
	return min(s1, s2);
}

int main()
{
	int n; cin >> n;
	while (n --)
	{
		for (int i = 0; i < 6; i ++) cin >> a[i];

		string t;
		for (int i = 0; i < 6; i ++)
			if (i == 0) t = work(i);
			else t = min(t, work(i));
		
		if (mp.find(t) != mp.end()) 
		{
			cout << "Twin snowflakes found.";
			return 0;
		}
		else mp[t] = true;
	}
	cout << "No two snowflakes are alike.";
	return 0;
}
/**
 * @file B. Different String.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-15
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void solve()
{
	string s; cin >> s;
	bool ok = false;
	for (int i = 1; i < s.size(); i ++)
		if (s[i] != s[0])
		{
			swap(s[0], s[i]);
			ok = true;
			break;
		}
	if (!ok) cout << "NO\n";
	else cout << "YES\n" << s << endl;
}

int main()
{
	int t; cin >> t;
	while (t --)
		solve();
}
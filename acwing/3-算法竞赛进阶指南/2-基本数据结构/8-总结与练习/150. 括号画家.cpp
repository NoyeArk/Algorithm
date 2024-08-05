/**
 * @file 150. 括号画家.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-04
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <stack>
#include <map>
using namespace std;

stack<int> stk;
map<char, char> mp = {{')', '('}, {'}', '{'}, {']', '['}};

int main()
{
	string s; cin >> s;

	int ans = 0;
	for (int i = 0; i < s.size(); i ++)
	{
		if ((s[i] == ')' || s[i] == '}' || s[i] == ']') 
			&& stk.size() && mp[s[i]] == s[stk.top()]) stk.pop();
		else stk.push(i);

		if (stk.size()) ans = max(ans, i - stk.top());
		else ans = max(ans, i + 1);
	}
	cout << ans;

	return 0;
}
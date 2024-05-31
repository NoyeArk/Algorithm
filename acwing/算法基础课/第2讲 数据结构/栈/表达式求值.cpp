/**
 * @file 表达式求值.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-31
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

stack<int> num;
stack<char> op;

void eval()
{
	auto b = num.top(); num.pop();
	auto a = num.top(); num.pop();
	auto c = op.top(); op.pop();
	int res = 0;
	if (c == '+') res = a + b;
	else if (c == '-') res = a - b;
	else if (c == '*') res = a * b;
	else if (c == '/') res = a / b;
	num.push(res);
}

int main()
{
	unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

	string str; cin >> str;
	for (int i = 0; i < str.size(); i ++)
	{
		auto c = str[i];
		if (isdigit(c))
		{
			int x = 0, j = i;
			while (j < str.size() && isdigit(str[j]))
				x = x * 10 + str[j ++] - '0';
			i = j - 1;
			num.push(x);
		}
		else if (c == '(') op.push(c);
		else if (c == ')')
		{
			while (op.top() != '(') eval();
			op.pop();
		}
		else
		{
			while (op.size() && op.top() != '(' && pr[op.top()] >= pr[c])
				eval();
			op.push(c);
		}
	}
	while (op.size()) eval();
	
	cout << num.top();
	return 0;
}
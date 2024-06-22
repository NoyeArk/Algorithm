/**
 * @file 单调栈.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-23
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int stk[N], top;

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) 
	{
		int x; cin >> x;
		while (top && stk[top] >= x) top --;
		if (top) cout << stk[top] << " ";
		else cout << -1 << " ";
		stk[++ top] = x;
	}

	return 0;
}
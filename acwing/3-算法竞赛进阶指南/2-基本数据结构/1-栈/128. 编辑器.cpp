/**
 * @file 128. 编辑器.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-07-07
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	维护3个栈：
 * 	1、I和R的操作是在左边的栈插入一个元素
 * 	2、D操作是将左栈中的栈顶元素弹出
 * 	3、L操作是将左栈的栈顶元素弹出并将其入右栈
 */

#include <iostream>
#include <limits.h>
using namespace std;

const int N = 1000010;
int stkl[N], stkr[N], tl, tr;
int f[N], sum[N];

void add(int x)
{
	stkl[++ tl] = x;
	sum[tl] = sum[tl - 1] + x;
	f[tl] = max(f[tl - 1], sum[tl]);
}

int main()
{
	int q; cin >> q;
	f[0] = INT_MIN;
	while (q --)
	{
		char op; cin >> op;
		int x, k;
		if (op == 'I')
		{
			cin >> x;
			add(x);
		}
		else if (op == 'D')
		{
			if (tl) tl --;
		}
		else if (op == 'L')
		{
			if (tl) stkr[++ tr] = stkl[tl --];
		}
		else if (op == 'R')
		{
			if (tr) add(stkr[tr --]);
		}
		else 
		{
			cin >> k;
			cout << f[k] << endl;
		}
	}

	return 0;
}
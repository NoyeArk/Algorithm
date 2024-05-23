/**
 * @file 邻接表.cpp
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
int h[N], e[N], ne[N], idx;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int main()
{
	int n; cin >> n;
	while (n --)
	{
		int a, b; cin >> a >> b;
		add(a, b);
	}
	return 0;
}
/**
 * @file 模拟散列表.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-26
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 100003;
int h[N], e[N], ne[N], idx;

void insert(int x)
{
	int k = (x % N + N) % N;
	e[idx] = x, ne[idx] = h[k], h[k] = idx ++;
}

bool query(int x)
{
	int k = (x % N + N) % N;
	for (int i = h[k]; i != -1; i = ne[i])
		if (e[i] == x) return true;
	return false;
}

int main()
{
	memset(h, -1, sizeof h);
	int n; cin >> n;
	while (n --)
	{
		char op;
		int x; cin >> op >> x;
		if (op == 'I') insert(x);
		else cout << (query(x) ? "Yes" : "No") << endl;
	}
	return 0;
}
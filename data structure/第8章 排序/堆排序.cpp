/**
 * @file 堆排序.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-21
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 1010;
int h[N], len;

void down(int u)
{
	int t = u;
	if (2 * u <= len && h[2 * u] < h[t]) t = 2 * u; 
	if (2 * u + 1 <= len && h[2 * u + 1] < h[t]) t = 2 * u + 1;
	if (t != u) 
	{
		swap(h[t], h[u]);
		down(t);
	}
}

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) cin >> h[i];

	len = n;
	for (int i = len / 2; i; i --) down(i);

	while (n --)
	{
		cout << h[1] << " ";
		h[1] = h[len --];
		down(1);
	}

	return 0;
}
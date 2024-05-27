/**
 * @file 1-未初始化警告.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-27
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
bool st[N];

int main()
{
	st[0] = true;
	int n, k; cin >> n >> k;

	int ans = 0;
	while (k --)
	{
		int x, y; cin >> x >> y;
		if (!st[y]) ans ++;
		st[x] = true;
	}

	cout << ans;
	return 0;
}
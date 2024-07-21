/**
 * @file Nim游戏.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-07-21
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	先手必胜状态：可以走到某一个必败状态
 * 	先手必败状态：走不到任何一个必败状态
 */

#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;

	int ans = 0;
	while (n --)
	{
		int x; cin >> x;
		ans ^= x;
	}

	cout << (ans ? "Yes" : "No");
	return 0;
}
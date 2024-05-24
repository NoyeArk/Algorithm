/**
 * @file Nim游戏.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-24
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int a[N];

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];

	int cnt = 0;
	for (int i = 1; i <= n; i ++) 
		if (a[i] == 1) cnt ++;

	if (cnt & 1) cout << (((n - cnt) % 2 == 0) ? "No" : "Yes");
	else cout << (((n - cnt) % 2 == 0) ? "Yes" : "No");

	return 0;
}
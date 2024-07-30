/**
 * @file E. Find the Car.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-07-30
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010, M = 1e9 + 5;
int a[N], b[N], dist[M];

void work()
{
	int n, k, q; cin >> n >> k >> q;
	for (int i = 1; i <= k; i ++) cin >> a[i];
	for (int i = 1; i <= k; i ++) cin >> b[i];

	for (int i = 1; i <= k; i ++)
	{
		double speed = (double)(a[i] - a[i - 1]) / (b[i] - b[i - 1]);
		for (int j = a[i - 1]; j <= a[i]; j ++)
			dist[j] = (int)(dist[j - 1] + speed);
	}

	while (q --)
	{
		int d; cin >> d;
		cout << dist[d] << endl;
	}
}

int main()
{
	int t; cin >> t;
	while (t --) work();
	return 0;
}
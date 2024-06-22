/**
 * @file 收集卡牌.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-12
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 16, M = 1 << N;
int n, m;
double p[N], f[M][85];

double dp(int state, int coin, int r)
{
	double &v = f[state][coin];
	if (v >= 0) return v;
	if (coin >= r * m) return v = 0;

	v = 0;
	for (int i = 0 ; i < n; i ++)
		if (state >> i & 1)
			v += p[i] * (dp(state, coin + 1, r) + 1);
		else
			v += p[i] * (dp(state | (1 << i), coin, r - 1) + 1);
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> p[i];

	memset(f, -1, sizeof f);

	printf("%.10lf", dp(0, 0, n));
	return 0;
}
/**
 * @file 子矩阵.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-10
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	使用两次单调队列进行处理
 */

#include <iostream>
using namespace std;

typedef long long LL;

const int N = 1010, mod = 998244353;
int n, m, A, B;
int w[N][N];
int q[N];
int rmax[N][N], rmin[N][N];

void get_max(int a[], int b[], int len, int k)
{
	int hh = 0, tt = -1;
	for (int i = 1; i <= len; i ++)
	{
		if (hh <= tt && q[hh] <= i - k) hh ++;
		while (hh <= tt && a[q[tt]] <= a[i]) tt --;
		q[++ tt] = i;
		b[i] = a[q[hh]];
	}
}

void get_min(int a[], int b[], int len, int k)
{
	int hh = 0, tt = -1;
	for (int i = 1; i <= len; i ++)
	{
		if (hh <= tt && q[hh] <= i - k) hh ++;
		while (hh <= tt && a[q[tt]] >= a[i]) tt --;
		q[++ tt] = i;
		b[i] = a[q[hh]];
	}
}

int main()
{
	cin >> n >> m >> A >> B;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			cin >> w[i][j];

	for (int i = 1; i <= n; i ++) get_max(w[i], rmax[i], m, B);
	for (int i = 1; i <= n; i ++) get_min(w[i], rmin[i], m, B);

	int a[N], b[N], c[N], res = 0;
	for (int i = B; i <= m; i ++)
	{
		for (int j = 1; j <= n; j ++) a[j] = rmax[j][i];
		get_max(a, b, n, A);
		for (int j = 1; j <= n; j ++) a[j] = rmin[j][i];
		get_min(a, c, n, A);
		for (int j = A; j <= n; j ++)
			res = (res + (LL)b[j] * c[j]) % mod;
	}

	cout << res;
	return 0;
}
/**
 * @file 3-登机牌条码.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-29
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 2010, mod = 929;
int w, s, k;
char str[N];
int d[N], cnt;

void get_d()
{
	int mode = 0;
	for (int i = 0; str[i]; i ++)
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (mode == 1)
				d[++ cnt] = 28, d[++ cnt] = 28;
			else if (mode == 2)
				d[++ cnt] = 28;
			mode = 0, d[++ cnt] = str[i] - 'A';
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (mode != 1)
				d[++ cnt] = 27;
			mode = 1, d[++ cnt] = str[i] - 'a';
		}
		else
		{
			if (mode != 2)
				d[++ cnt] = 28;
			mode = 2, d[++ cnt] = str[i] - '0';
		}
	if (cnt & 1) d[++ cnt] = 29;
	for (int i = 1, j = 1; i < cnt; i += 2, j ++)
		d[j] = 30 * d[i] + d[i + 1];
	cnt >>= 1;
	while ((cnt + 1 + k) % w) d[++ cnt] = 900;
	d[0] = cnt + 1;
}

int g[N];
void get_g()
{
	g[0] = 1;
	int r = -3;
	for (int i = 1; i <= k; r = r * 3 % mod, i ++)
		for (int j = i - 1; j >= 0; j --)
			g[j + 1] = (g[j + 1] + g[j] * r) % mod;
}

int main()
{
	cin >> w >> s >> str;
	k = s == -1 ? 0 : 1 << s + 1;
	get_d();
	get_g();
	return 0;
}
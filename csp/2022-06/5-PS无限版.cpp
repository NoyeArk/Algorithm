/**
 * @file 5-PS无限版.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-26
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <map>
#define first x
#define second y
using namespace std;

typedef pair<double, double> PDD;

const int N = 100010;
PDD p[N];

void shift()
{
	int l, r, a, b; cin >> l >> r >> a >> b;
	for (int i = l; i <= r; i ++)
		p[i].x += a, p[i].y += b;
}

int main()
{
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i ++) cin >> p[i].x >> p[i].y;

	while (q --)
	{
		int op; cin >> op;
		if (op == 1) shift();
		else if (op == 2) 
	}

	return 0;
}
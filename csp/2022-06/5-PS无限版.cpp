/**
 * @file 5-PS无限版.cpp
 * @author horiki
 * @version 0.2
 * @date 2024-05-26 2024-05-27
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <cmath>
#include <map>
#define x first
#define y second
using namespace std;

typedef pair<double, double> PDD;

const int N = 100010;
PDD p[N];

void shift()
{
	int l, r;
	double a, b; cin >> l >> r >> a >> b;
	for (int i = l; i <= r; i ++)
		p[i].x += a, p[i].y += b;
}

void rotate()
{
	int l, r;
	double a, b, pp; cin >> l >> r >> a >> b >> pp;
	for (int i = l; i <= r; i ++)
	{
		double diff_x = p[i].x - a, diff_y = p[i].y - b;
		p[i].x = a + diff_x * cos(pp) - diff_y * sin(pp);
		p[i].y = b + diff_x * sin(pp) + diff_y * cos(pp);
	}
}

void scale()
{
	int l, r;
	double a, b, pp; cin >> l >> r >> a >> b >> pp;
	for (int i = l; i <= r; i ++)
	{
		double diff_x = p[i].x - a;
		double diff_y = p[i].y - b;
		diff_x *= pp, diff_y *= pp;
		p[i].x = a + diff_x, p[i].y = b + diff_y;
	}
}

void get_core()
{
	int l, r; cin >> l >> r;
	double sum_x = 0, sum_y = 0;
	for (int i = l; i <= r; i ++)
		sum_x += p[i].x, sum_y += p[i].y;
	sum_x /= (r - l + 1), sum_y /= (r - l + 1);
	printf("%.6lf %.6lf\n", sum_x, sum_y);
}

void get_square()
{
	int l, r;
	double a, b; cin >> l >> r >> a >> b;
	double ans = 0;
	for (int i = l; i <= r; i ++)
		ans += pow((p[i].x - a), 2) + pow((p[i].y - b), 2);
	printf("%.6lf\n", ans);
}

int main()
{
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i ++) cin >> p[i].x >> p[i].y;

	while (q --)
	{
		int op; cin >> op;
		if (op == 1) shift();
		else if (op == 2) rotate();
		else if (op == 3) scale();
		else if (op == 6) get_core();
		else if (op == 7) get_square();
	}

	return 0;
}
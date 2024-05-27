/**
 * @file 4-光线追踪.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-26
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

const int N = 1000010;
int cnt = 1;
struct Mirror
{
	int x1, y1, x2, y2;
	int k;
	double a;
	bool is_use;
}m[N];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

unordered_map<int, int> h;

void insert_mirror(int i)
{
	h[i] = cnt;

	int x1, y1, x2, y2; 
	double a; cin >> x1 >> y1 >> x2 >> y2 >> a;
	m[cnt].x1 = x1, m[cnt].x2 = x2, m[cnt].y1 = y1, m[cnt].y2 = y2;
	m[cnt].a = a, m[cnt].is_use = true;
	if ((x1 - x2) * (y1 - y2) > 0) m[cnt].k = 1;
	else m[cnt].k = -1;
 	cnt ++;
}

void remove()
{
	int k; cin >> k;
	m[h[k]].is_use = false;
}

// 判断点(x, y)是否有镜子
void update(int x, int y, int& d, double& I)
{
	for (int i = 1; i <= cnt; i ++)
	{
		if (!m[i].is_use) continue;
		if ((x == m[i].x1 && y == m[i].y1) || (x == m[i].x2 && y == m[i].y2))
			continue;

		if ((m[i].y1 - y) * (m[i].x2 - x) == (m[i].y2 - y) * (m[i].x1 - x))
		{
			if (y > max(m[i].y1, m[i].y2) || y < min(m[i].y1, m[i].y2))
				continue;
			if (x > max(m[i].x1, m[i].x2) || x < min(m[i].x1, m[i].x2))
				continue;
			// 进行反射 改变方向
			if (m[i].k < 0)
			{
				if (d == 0) d = 3;
				else if (d == 1) d = 2;
				else if (d == 2) d = 1;
				else if (d == 3) d = 0;
			}
			else 
			{
				if (d == 0) d = 1;
				else if (d == 1) d = 0;
				else if (d == 2) d = 3;
				else if (d == 3) d = 2;
			}
			// 强度减弱
			I *= m[i].a;
			break;
		}
	}
	
}

void insert_laser()
{
	int x, y, d, t;
	double I; cin >> x >> y >> d >> I >> t;
	int a = x, b = y, cnt = 1;
	for (int i = 1; i <= t; i ++)
	{
		x += dx[d], y += dy[d];
		update(x, y, d, I);
// 		if (a == -716 && b == -381 && cnt % 100 == 0)
// 		{
// 			printf("x:%d y:%d I:%.2lf d:%d\n", x, y, I, d);
// 		}
		cnt ++;
		if (I < 1) break;
	}
	if (I < 1) printf("0 0 0\n");
	else cout << x << " " << y << " " << floor(I) << endl;
}

int main()
{
	int m; cin >> m;
	for (int i = 1; i <= m; i ++)
	{
		int op; cin >> op;
		if (op == 1) insert_mirror(i);
		else if (op == 2) remove();
		else insert_laser();
	}

	return 0;
}
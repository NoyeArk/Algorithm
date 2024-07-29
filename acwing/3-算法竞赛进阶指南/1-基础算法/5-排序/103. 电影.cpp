/**
 * @file 103. 电影.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-24
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	相当于收集每个电影的信息，然后对于每个电影进行排序
 */

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int N = 200010;
unordered_map<int, int> mp;
struct Movie
{
	int a, b, id;
}a[N];

bool cmp(Movie a, Movie b)
{
	if (a.a != b.a) return a.a > b.a;
	return a.b > b.b;
}

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) 
	{
		int x; cin >> x;
		mp[x] ++;
	}

	int m; cin >> m;
	for (int i = 1; i <= m; i ++) 
	{
		int x; cin >> x;
		a[i].a = mp[x];
	}
	for (int i = 1; i <= m; i ++)
	{
		int x; cin >> x;
		a[i].b = mp[x];
		a[i].id = i;
	}

	sort(a + 1, a + 1 + m, cmp);
	cout << a[1].id;

	return 0;
}
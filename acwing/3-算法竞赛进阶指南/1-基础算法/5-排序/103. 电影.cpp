/**
 * @file 103. 电影.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-24
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	把所有科学家懂得的语言进行排序，然后找是否存在这个语言的电影
 * 	感觉需要用到离散化
 * 	统计除了科学家懂得最多的是哪个语言之后，需要看一下是否存在这个语言
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#define x first
#define y second
using namespace std;

typedef long long LL;

const int N = 200010;
int a[N];
pair<int, int> movie[N];
unordered_map<int, int> mp;

vector<int> alls;

int find(int x)
{
	return lower_bound(alls.begin(), alls.end(), x) - alls.begin();
}

int main()
{
	int n; cin >> n;

	int mx = 0;
	vector<int> k;
	for (int i = 1; i <= n; i ++) 
	{
		int x; cin >> x;
		mp[x] ++;
		if (mp[x] == mx) k.push_back(x);
		else if (mp[x] > mx)
		{
			k.clear();
			k.push_back(x);
		}
	}
	int m; cin >> m;
	for (int i = 1; i <= m; i ++) cin >> movie[i].x >> movie[i].y;

	

	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());

	for (int i = 1; i <= m; i ++)


	return 0;
}
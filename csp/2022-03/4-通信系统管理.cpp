/**
 * @file 4-通信系统管理.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-27
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int N = 1010;
int n, m;
int h[N], e[N], ne[N], idx;

struct Link
{
	int st, time, w;
}link[N];

vector<int> nodes;

void add(int a, int b, int i, int wei, int time)
{
	e[idx] = b, ne[idx] = h[a];
	link[idx].st = i, link[idx].time = time, link[idx].w = wei;
	h[a] = idx ++;
}

bool check(int id, int day)
{
	int st = link[id].st, ed = link[id].st + link[id].time - 1;
	return st <= day && day <= ed;
}

int query(int q, int day)
{
	// 查询机器id第day天的通信主要对象
	unordered_map<int, int> hh;
	// 找出第day天能与该机器进行通信的其他机器
	for (int i = h[q]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (check(i, day))
		{
			if (hh.find(j) == hh.end())
				hh[j] = link[i].w;
			else hh[j] += link[i].w;
		}
	}
	int res = 0, mx = 0;
	for (auto it : hh)
	{
		if (it.second > mx)
			mx = it.second, res = it.first;
	}
	return res;
}

int query_ioslate(int day)
{
	int res = 0;
	for (auto t : nodes)
	{
		bool is_ioslate = true;
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (check(i, day))
			{
				is_ioslate = false;
				break;
			}
		}
		if (is_ioslate) res ++;
	}
	return n - nodes.size() + res;
}

int query_pair(int day)
{
	int res = 0;
	unordered_map<int, int> hh;
	
	for (auto t : nodes)
	{
		int id = query(t, day);
		if (id == -1) continue;
		if (hh.find(id) != hh.end())
		{
			if (hh[id] == t)
				res ++;
		}
		else hh[t] = id;
	}
	return res;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	// 第i天
	for (int i = 1; i <= m; i ++)
	{
		int k; cin >> k;
		while (k --)
		{
			int u, v, x, y; cin >> u >> v >> x >> y;
			add(u, v, i, x, y);
			add(v, u, i, x, y);
			nodes.push_back(u);
			nodes.push_back(v);
		}
		sort(nodes.begin(), nodes.end());
		nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
		// 查询
		int l; cin >> l;
		while (l --)
		{
			int q; cin >> q;
			cout << query(q, i) << endl;
		}
		// 是否要查询通信孤岛和通信对
		int p, q; cin >> p >> q;
		if (p) cout << query_ioslate(i) << endl;
		if (q) cout << query_pair(i) << endl;
	}

	return 0;
}
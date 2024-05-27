/**
 * @file 3-计算资源调度器.cpp
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
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef pair<int, int> PII;

const int N = 1010;
int n, m;
int h[N], e[N], ne[N], idx;

struct Node
{
	vector<int> task;
	bool is_use;
}calc[N];

bool st[N];
vector<int> all_areas;
unordered_map<int, vector<int>> a2ids;

vector<int> get_area(int na, int pa)
{
	vector<int> res;
	// na表示必须运行在编号为na的可用区的计算结点上
	if (na != 0)
	{
		if (na == -1) return vector<int>();
		else res.push_back(na);
	}
	else if (na == 0)
	{
		if (pa != 0)
		{
			// pa表示必须运行在编号为na的应用的可用区的计算节点上
			auto tmp = a2ids[pa];
			res.insert(res.end(), tmp.begin(), tmp.end());
		}
		else res = all_areas;
	}
	return res;
}

void print_none(int n)
{
	for (int i = 1; i <= n; i ++)
		cout << 0 << " ";
	cout << endl;
}

bool check(int id, int paa)
{
	for (auto t : calc[id].task)
		if (t == paa) return false;
	return true;
}

bool cmp(PII& a, PII& b)
{
	if (a.first != b.first) return a.first < b.first;
	return a.second < b.second;
}

int allocate(vector<int> area, int a, int paa, int paar)
{
	vector<PII> ids;
	vector<PII> ids_p;
	for (auto t : area)
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			// 判断计算结点j是否满足计算任务反亲和性
			if (check(j, paa))
				ids.push_back({calc[j].task.size(), j});
			ids_p.push_back({calc[j].task.size(), j});
		}
	
	if (ids.empty())
	{
		if (ids_p.empty() || paar == 1) return 0;
		ids = ids_p;
	}

	// 排序
	sort(ids.begin(), ids.end(), cmp);

	int tar = ids[0].second;
	
	// 将该任务所属的应用a分配到该结点
	calc[tar].task.push_back(a);
	return tar;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	// 读入计算节点i所属的可用区
	for (int i = 1; i <= n; i ++) 
	{
		int l; cin >> l;
		if (!st[l])
		{
			st[l] = true;
			all_areas.push_back(l);
		}
		e[idx] = i, ne[idx] = h[l], h[l] = idx ++;
	}

	int g; cin >> g;
	while (g --)
	{
		int f, a, na, pa, paa, paar;
		cin >> f >> a >> na >> pa >> paa >> paar;
		bool ans = true;
		// 判断是否有计算结点亲和性要求
		auto areas = get_area(na, pa);
		if (areas.empty()) 
		{
			print_none(f);
			continue;
		}

		bool is_ok = false;
		// 一共有f个任务
		while (f --)
		{
			auto res = allocate(areas, a, paa, paar);
			cout << res << " ";
			if (res != 0) is_ok = true;
		}
		cout << endl;
		if (is_ok) 
			a2ids[a].insert(a2ids[a].end(), areas.begin(), areas.end());
	}

	return 0;
}
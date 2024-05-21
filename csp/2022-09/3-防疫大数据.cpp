/**
 * @file 3-防疫大数据.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-20
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Area
{
	int id;
	int time;
	vector<int> user;
};

vector<Area> area;
unordered_map<int, int> h;

void update()
{
	for (auto a : area)
		a.time ++;
}

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		vector<int> ans;
		int r, m; cin >> r >> m;
		// 收到的风险地区信息
		for (int j = 1; j <= r; j ++)
		{
			int id; cin >> id;
			if (h.find(id) != h.end())
				area[h[id]].time = 1;
			else 
			{
				area.push_back({id, 1, vector<int>{}});
				h[id] = area.size() - 1;
			}
		}
		// 收到的漫游数据的条目
		for (int j = 1; j <= m; j ++)
		{
			int d, u, r; cin >> d >> u >> r;
			if (h.find(r) != h.end())
			{
				int idx = h[r];
				if (7 - area[idx].time + i - 1 >= d && d >= i - 1)
					ans.push_back(u);
			}
		}
		update();

		sort(ans.begin(), ans.end());
		cout << i - 1 << " ";
		for (auto t : ans) cout << t << " ";
		cout << endl;
	}

	return 0;
}
/**
 * @file 132. 小组队列.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-07-09
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	使用队列维护所有信息，N个小队入队出队的信息用q[N][N]来维护
 * 	队列head用来维护队列中每个小队的先后顺序
 */

#include <iostream>
#include <queue>
#include <cstring>
#include <unordered_map>
using namespace std;

const int N = 1010;
int q[N][N], hh[N], tt[N];
queue<int> head;

unordered_map<int, int> mp;

int main()
{
	int t, count = 0;
	while (cin >> t && t != 0)
	{
		head = queue<int>();
		memset(hh, 0, sizeof hh);
		memset(tt, -1, sizeof tt);
		printf("Scenario #%d\n", ++ count);

		for (int i = 1; i <= t; i ++)
		{
			int cnt; cin >> cnt;
			for (int j = 1; j <= cnt; j ++)
			{
				int x; cin >> x;
				mp[x] = i;
			}
		}
		string op;
		while (cin >> op && op != "STOP")
		{
			if (op == "ENQUEUE")
			{
				int x; cin >> x;
				// 编号为x是第几小队
				int id = mp[x];
				if (hh[id] > tt[id]) head.push(id);
				q[id][++ tt[id]] = x;
			}
			else 
			{
				// 整个队列的第一个小队
				int id = head.front();;
				cout << q[id][hh[id] ++] << endl;
				if (hh[id] > tt[id]) head.pop();
			}
		}
		cout << endl;
	}

	return 0;
}
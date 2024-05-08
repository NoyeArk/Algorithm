/**
 * @file 八数码.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-26
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  1.状态表示比较复杂
 *  2.如何记录每个状态的距离
 */

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int bfs(string st)
{
    string end = "12345678x";

    queue<string> q;
    unordered_map<string, int> dist;

    q.push(st);
    dist[st] = 0;

    while (q.size())
    {
        auto t = q.front(); q.pop();
        int d = dist[t];

        if (t == end) return d;

        // 状态转移
        int k = t.find('x');
        int x = k / 3, y = k % 3;

        for (int i = 0; i < 4; i ++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(t[k], t[a * 3 + b]);
                if (!dist.count(t))
                {
                    dist[t] = d + 1;
                    q.push(t);
                }
                swap(t[k], t[a * 3 + b]);
            }
        }
    }
    return -1;
}

int main()
{
    string st;
    for (int i = 0; i < 9; i ++)
    {
        char c; cin >> c;
        st += c;
    }
    cout << bfs(st) << endl;
    return 0;
}
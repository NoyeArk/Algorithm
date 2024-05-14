/**
 * @file 奶牛回家.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-13
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  1.大写字母标记的牧场中都存在一头奶牛
 *  2.小写字母标记的牧场中都不存在奶牛
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int N = 55;
int g[N][N];
int dist[N];
bool st[N];
vector<char> have;
unordered_map<char, int> h;

void init()
{
    // 初始化字母到数字的映射
    for (int i = 0; i < 26; i ++)
        h['a' + i] = i, h['A' + i] = i + 26;
    memset(g, 0x3f, sizeof g);
}

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[h['Z']] = 0;
    for (int i = 0; i <= 51; i ++)
    {   
        int t = -1;
        for (int j = 0; j <= 51; j ++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        st[t] = true;
        for (int j = 0; j <= 51; j ++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
}

int main()
{
    init();
    int p; cin >> p;
    while (p --)
    {
        int c;
        char a, b; cin >> a >> b >> c;
        g[h[a]][h[b]] = g[h[b]][h[a]] = min(g[h[a]][h[b]], c);
        if (a < 'a' && a != '.') have.push_back(a);
        if (b < 'a' && b != '.') have.push_back(b);
    }

    sort(have.begin(), have.end());
    have.erase(unique(have.begin(), have.end()), have.end());
    
    for (auto c : have)
        printf("%c ", c);
    cout << endl;

    dijkstra();
    
    int ans = 1e9; char t;
    for (auto c : have)
        if (c == 'Z') continue;
        else 
        {
            cout << dist[h[c]] << " " << c << endl;
            if (ans > dist[h[c]]) 
                ans = dist[h[c]], t = c;
        }
    cout << t << " " << ans;
    return 0;
}
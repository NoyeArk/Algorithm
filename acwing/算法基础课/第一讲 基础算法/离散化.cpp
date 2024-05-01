/**
 * @file 离散化.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-01
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 300010;
int a[N], pre[N];
vector<int> alls;
vector<PII> query, add;

int find(int x)
{
    return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
}

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        int x, c; cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }

    for (int i = 1; i <= m; i ++)
    {
        int l, r; cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (auto it : add)
    {
        int x = find(it.first);
        a[x] += it.second;
    }

    for (int i = 1; i <= alls.size(); i ++) 
        pre[i] = pre[i - 1] + a[i];

    for (auto it : query)
    {
        int l = find(it.first), r = find(it.second);
        cout << pre[r] - pre[l - 1] << endl;
    }

    return 0;
}
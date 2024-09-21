/**
 * @file 802. 区间和.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-11
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
int pre[N];

vector<int> alls;
vector<PII> p, q;

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
        p.push_back({x, c});
        alls.push_back(x);
    }

    for (int i = 1; i <= m; i ++)
    {
        int l, r; cin >> l >> r;
        q.push_back({l, r});
        alls.push_back(l), alls.push_back(r);
    }

    // 离散化
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    // 指定位置的元素加c
    for (auto it : p)
        pre[find(it.first)] += it.second;

    for (int i = 1; i <= alls.size(); i ++)
        pre[i] += pre[i - 1];

    // 处理查询请求
    for (auto it : q)
        cout << pre[find(it.second)] - pre[find(it.first) - 1] << endl;

    return 0;
}
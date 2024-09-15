/**
 * @file 802. 区间和 1.cpp
 * @author horiki
 * @date 2024-09-14
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 200010;
int a[N];
vector<int> alls;
vector<PII> adds, querys;

int find(int x)
{
    return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
}

int main()
{
    int n, m; cin >> n >> m;
    while (n --)
    {
        int x, c; cin >> x >> c;
        alls.push_back(x);
        adds.push_back({x, c});
    }
    while (m --)
    {
        int l, r; cin >> l >> r;
        querys.push_back({l, r});
        alls.push_back(l), alls.push_back(r);
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (auto [x, c] : adds) a[find(x)] += c;
    for (int i = 1; i <= alls.size(); i ++) a[i] += a[i - 1];
    for (auto [l, r] : querys) cout << a[find(r)] - a[find(l) - 1] << endl;

    return 0;
}
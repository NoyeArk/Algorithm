/**
 * @file 4-聚集方差.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-13
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 300010;
int n;
int p[N], a[N], result[N];
int h[N], e[N], ne[N], idx;

vector<int> dfs(int u)
{
    vector<int> T;
    T.push_back(a[u]);
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        auto tmp = dfs(j);
        T.insert(T.end(), tmp.begin(), tmp.end());
    }
    // 计算Ansu
    int ans = 0;
    sort(T.begin(), T.end());
    for (int i = 0; i < T.size(); i ++)
    {
        int tmp = 2e9;
        if (i > 0) tmp = min(tmp, (T[i] - T[i - 1]) * (T[i] - T[i - 1]));
        if (i < T.size() - 1) tmp = min(tmp, (T[i] - T[i + 1]) * (T[i] - T[i + 1]));
        ans += tmp;
    }
    if (T.size() == 1) ans = 0;
    result[u] = ans;

    return T;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 2; i <= n; i ++) 
    {
        int x; cin >> x;
        e[idx] = i, ne[idx] = h[x], h[x] = idx ++;
    }
    for (int i = 1; i <= n; i ++) cin >> a[i];

    auto tmp = dfs(1);
    for (int i = 1; i <= n; i ++) cout << result[i] << endl;

    return 0;
}
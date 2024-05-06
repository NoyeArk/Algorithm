/**
 * @file 连通块中点的数量.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-06
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int pre[N], cnt[N];

int find(int x)
{
    return pre[x] = (pre[x] == x ? x : find(pre[x]));
}

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) pre[i] = i, cnt[i] = 1;
    while (m --)
    {
        int a, b;
        string op; cin >> op;
        if (op == "C") 
        {
            cin >> a >> b;
            a = find(a), b = find(b);
            if (a != b) pre[a] = b, cnt[b] += cnt[a];
        }
        else if (op == "Q1")
        {
            cin >> a >> b;
            cout << (find(a) == find(b) ? "Yes" : "No") << endl;
        }
        else
        {
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }

    return 0;
}
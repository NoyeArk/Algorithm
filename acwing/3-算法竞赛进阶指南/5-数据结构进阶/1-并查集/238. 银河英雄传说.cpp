/**
 * @file 238. 银河英雄传说.cpp
 * @author horiki
 * @date 2024-08-16
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 30010;
int pre[N], cnt[N];

int find(int x)
{
    return pre[x] = (pre[x] == x ? x : find(pre[x]));
}

int main()
{
    for (int i = 1; i < N; i ++) pre[i] = i, cnt[i] = 1;
    int t; cin >> t;
    while (t --)
    {
        char op; int i, j; cin >> op >> i >> j;
        if (op == 'M') pre[find(i)] = find(j), cnt[i] += cnt[j];
        else if (find(i) != find(j)) cout << -1 << endl;
        else cout << cnt[find(j)] - cnt[find(i)] << endl;
    }

    return 0;
}
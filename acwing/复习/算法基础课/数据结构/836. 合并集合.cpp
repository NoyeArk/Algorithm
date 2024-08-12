/**
 * @file 836. 合并集合.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-12
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int pre[N];

int find(int x)
{
    return pre[x] = (pre[x] == x ? x : find(pre[x]));
}

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) pre[i] = i;

    while (m --)
    {
        char op; int a, b; cin >> op >> a >> b;
        if (op == 'M') pre[find(a)] = find(b);
        else cout << (find(a) == find(b) ? "Yes" : "No") << endl;
    }

    return 0;
}
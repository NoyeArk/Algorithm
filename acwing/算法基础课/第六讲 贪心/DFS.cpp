/**
 * @file DFS.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-29
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

int n, path[9];
bool vis[9];

void dfs(int u)
{
    if (u > n) 
    {
        for (int i = 1; i <= n; i ++) 
            cout << path[i] << " ";
        cout << endl;
        return ;
    }

    for (int i = 1; i <= n; i ++)
    {
        if (vis[i]) continue;
        vis[i] = true;
        path[u] = i;
        dfs(u + 1);
        vis[i] = false;
    }
}

int main()
{
    cin >> n;
    dfs(1);
    return 0;
}
/**
 * @file n-皇后问题.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-10
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int N = 30;

int n;
bool col[N], row[N], pos[N], neg[N];
vector<int> path;

void dfs(int u)
{
    if (u > n)
    {
        for (auto p : path)
        {
            for (int i = 1; i <= n; i ++)
                if (i == p) cout << "Q";
                else cout << ".";
            cout << endl;
        }
        cout << endl;
        return ;
    }
    
    for (int j = 1; j <= n; j ++)
    {
        if (col[j] || pos[u - j] || neg[u + j]) continue;
        // i, j放置一个皇后
        col[j] = true;
        pos[u - j] = true, neg[u + j] = true;
        path.push_back(j);

        dfs(u + 1); 

        col[j] = false;
        pos[u - j] = false, neg[u + j] = false;
        path.pop_back();
    }
}

int main()
{
    cin >> n;
    dfs(1);
    return 0;
}
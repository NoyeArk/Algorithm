/**
 * @file 237. 程序自动分析.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  先将e=1的i和j使用并查集进行维护，之后对e=0的元素i和j查询是否处于同一个集合中
 *  如果位于同一个集合，那么输出NO，否则为YES
 *  注意，本题需要对输入的i和j进行离散化
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int N = 200010;
int pre[N];
vector<int> all;

int find(int x)
{
    return pre[x] = (pre[x] == x ? x : find(pre[x]));
}

int get(int x)
{
    return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
}

void work()
{
    all.clear();
    int n; cin >> n;
    vector<pair<int, int>> q1, q2;

    while (n --)
    {
        int i, j, e; cin >> i >> j >> e;
        if (e) q1.push_back({i, j});
        else q2.push_back({i, j});
        all.push_back(i), all.push_back(j);
    }
    
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    
    for (int i = 1; i <= all.size(); i ++) pre[i] = i;
    
    // 处理e=1的请求
    for (auto it : q1)
        pre[find(get(it.first))] = find(get(it.second));
        
    // 处理e=0的请求
    for (auto it : q2)
        if (find(get(it.first)) == find(get(it.second))) 
        {
            cout << "NO" << endl;
            return ;
        }
    cout << "YES" << endl;
}

int main()
{
    int t; cin >> t;
    while (t --) work();
    return 0;
}
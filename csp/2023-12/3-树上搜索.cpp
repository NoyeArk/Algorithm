/**
 * @file 3-树上搜索.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-06
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  1.后代类别:若该类别没有次级类别，则该类别没有后代类别；
 *      否则该类别的后代类别为该类别的所有次级类别，以及其所有次级类别的后代类别。
 *  2.每个类别都可以赋予一个被称为权重的值，值越大，说明一个名词属于该类别的可能性越大。
 * 
 *  解题思路：
 *  1.先预处理所有结点的w
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <bitset>
using namespace std;

const int N = 2010;
struct Node
{
    int w, wp;
    vector<int> ne;
}node[N];

int n, m;
bitset<N> st; 
vector<int> path;

void dfs(int u)
{
    node[u].wp = node[u].w;
    if (node[u].ne.empty())  return ;

    for (auto child : node[u].ne)
    {
        if (st.test(child)) continue;
        dfs(child);
        node[u].wp += node[child].wp;
    }
}

void find_min(int u, int other_wp, int& min_id, int& v)
{
    for (auto child : node[u].ne)
        find_min(child, node[u].wp - node[child].wp + other_wp, min_id, v);
    node[u].wp = abs(node[u].wp - other_wp);

    if (node[u].wp < v) 
    {
        v = min(v, node[u].wp);
        min_id = u;
    }
    else if (node[u].wp == v) min_id = min(min_id, u);
}

void query(int target_class)
{
    int test_class, v;
    do
    {
        test_class = -1, v = 1e8;
        dfs(1);
        find_min(1, 0, test_class, v);

        path.push_back(test_class);
        st.set(test_class, 1);
    } while (test_class != target_class);

    // 判断test_class是否有孩子结点
    if (test_class == target_class && !node[test_class].ne.empty())
    {
        int tmp = test_class;

        test_class = -1, v = 1e8;
        dfs(tmp);
        find_min(tmp, 0, test_class, v);

        path.push_back(test_class);
        st.set(test_class, 1);
    }
    
    for (auto t : path)
        cout << t << " ";
    cout << endl;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> node[i].w;

    for (int i = 2; i <= n; i ++)
    {
        int x; cin >> x;
        // 编号为i的父亲为x
        node[x].ne.push_back(i);
    }

    while (m --)
    {
        int x; cin >> x;
        query(x);
    }

    return 0;
}
/**
 * @file 3-中序遍历.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-15
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

struct Node
{
    int v;
    int left, right;
}t[10];

const int a[] = {0, 1, 2, 3, 4, 5};

// 中序遍历：左子树-根-右子树
void dfs(int u)
{
    if (t[u].left) dfs(t[u].left);
    cout << t[u].v << " ";
    if (t[u].right) dfs(t[u].right);
}

int main()
{
    // 构建树
    for (int i = 0; i < 6; i ++) 
        t[i].v = i;
    t[0].left = 1, t[0].right = 2;
    t[1].left = 3, t[1].right = 4;
    t[2].left = 5;
    
    dfs(0);

    return 0;
}

/**
 *      0
 *    1    2
 *  3  4  5
 * 
 */
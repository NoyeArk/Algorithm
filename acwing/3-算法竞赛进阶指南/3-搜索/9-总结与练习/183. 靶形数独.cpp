/**
 * @file 183. 靶形数独.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-13
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  这题应该考察搜索，但是具体应该怎么执行搜索的逻辑呢
 *  一种暴力的做法就是，把每行、每列能够填的数字预处理出来，然后依次遍历所有可能性
 *  就是感觉好复杂，不知道怎么下手
 *  ----------------------------
 *  1.选择可选择数最少的一个空格来填
 *  2.使用二进制位运算来加速
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

const int N = 10;
int g[N][N];
vector<int> row[N], col[N];

int main()
{
    for (int i = 1; i <= 9; i ++)
        for (int j = 1; j <= 9; j ++) cin >> g[i][j];

    // 预处理行和列
    for (int i = 1; i <= 9; i ++)
        for (int j = 1; j <= 9; j ++)
        {
            if (g[i][j] == 0) row[i].push_back(j);
            if (g[j][i] == 0) col[j].push_back(i);
        }

    dfs

    return 0;
}
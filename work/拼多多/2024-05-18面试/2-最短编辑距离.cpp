/**
 * @file 2-最短编辑距离.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-18
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	给定两个字符串str1、str2，给定cost_insert、cost_delete、cost_replace分别表示插入、删除、替换一个字符的代价，
 * 	求str1转化为str2的最小代价。
 */

// 1.状态表示：f[i][j]表示将str1中以i结尾与str2中以j为结尾子串进行匹配
// str1[i] == str2[j]: f[i][j] = f[i - 1][j - 1]
// str1[i] != str2[j]: 
//      采用删除str1的第i个字符：那么str1[i - 1] == str2[j] f[i][j] = f[i - 1][j] + cost_delete
//      采用插入：f[i][j] = f[i][j - 1] + cost_insert
//      采用替换：f[i][j] = f[i - 1][j - 1] + cost_replace

#include <iostream>
using namespace std;

int f[10][10];
int cost_insert = 0, cost_delete= 1, cost_replace = 2;

int main()
{
    string str1 = " abcdf", str2 = " abddd"0
    
    for (int i = 1; i <= str1.size(); i ++) f[i][0] = i * cost_delete;
    for (int i = 1; i <= str2.size(); i ++) f[0][i] = i * cost_insert;
    
    for (int i = 1; i <= str1.size(); i ++)
        for (int j = 1; j <= str2.size(); j ++)
            if (str1[i] == str2[j]) f[i][j] = f[i - 1][j - 1];
            else
            {
                f[i][j] = min(f[i - 1][j] + cost_delete, f[i][j - 1] + cost_insert);
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + cost_replace);
            }
    
    cout << f[str1.size()][str2.size()];
    return 0;
}
/**
 * @file 1-最大数字.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-10
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  一定要删除k个数字，那么先从1开始删，然后删除2 ...
 * 链接：https://leetcode.cn/problems/remove-k-digits/
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> cnt[12];
int n;
string s; 

int main()
{
    cin >> s >> n;

    for (int i = 0; i < s.size(); i ++) 
        cnt[s[i] - '0'].push_back(i);

    for (int i = 0; i < 10; i ++)
    {
        while (cnt[i].size() && n)
        {
            int id = cnt[i][0];
            s[id] = 'x';
            cnt[i].erase(cnt[i].begin());
            n --;
        }
        if (!n) break;
    }

    for (int i = 0; i < s.size(); i ++)
        if (s[i] != 'x') cout << s[i];
    return 0;
}
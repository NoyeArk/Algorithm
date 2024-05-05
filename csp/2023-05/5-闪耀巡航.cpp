/**
 * @file 5-闪耀巡航.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-05
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 100010;
bool 
string s[N];
unordered_map<int, bool> h;

void work(int u)
{
    int ans = 0;
    string route = s[u];
    for (auto c : route)
    {
        if (h.find(c - 'a')) h[c - 'a'] = true;
    }
    // 判断是否完成
    
}

int main()
{
    string t;
    int n; cin >> n >> t;
    // 预处理目的地
    for (auto c : t)
        h[c - 'a'] = false;

    for (int i = 1; i <= n; i ++)
        cin >> s[i];

    for (int i = 1; i <= n; i ++)
        work(i);
    
    return 0;
}
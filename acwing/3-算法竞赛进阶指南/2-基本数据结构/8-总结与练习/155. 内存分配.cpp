/**
 * @file 155. 内存分配.cpp
 * @author horiki
 * @date 2024-08-22
 * 
 * @brief 
 *  mem[i]表示第i个内存单元还要被占用mem[i]时间
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 1000010;

struct Mem
{
    bool use;
    int t, p, size;
};
vector<int> mem;

int main()
{
    int n; cin >> n;
    mem.push_back(Mem(false, 0, 0, n));

    int t, m, p;
    while (cin >> t >> m >> p, t)
    {
        bool is_find = false;
        // 找到可用内存大于m的空间
        for (int i = 0; i < mem.size(); i ++)
        {
            if (mem[i].t + mem[i].p - 1 < t) mem[i].use = false;
            if (mem[i].use || mem[i].size < m) continue;
            // 判断是否需要分割内存空间
            if (mem[i].size == m) 
                mem[i].use = true, mem[i].t = t, mem[i].p = p;
            else
            {
                // 将mem[i]划分为mem[i]和mem[i + 1]
                mem.insert(mem.begin() + i, Mem(false, 0, 0, mem[i].size - m));
                // 更新mem[i]
                mem[i].use = true, mem[i].t = t, mem[i].p = p, mem[i].size = m;
            }
            is_find = true;
            break;
        }
        if (!is_find)
        {
            // 将其添加到阻塞队列中
            
        }
    }

    return 0;
}
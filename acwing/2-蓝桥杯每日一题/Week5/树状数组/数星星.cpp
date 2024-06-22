/**
 * @file 数星星.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-30
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	树状数组，下标从1开始
 *  可以支持的操作：
 *  1、区间修改
 *  2、单点查询
 *  3、区间查询
 * 
 *  时间复杂度：O(logn)
 */

#include <iostream>
using namespace std;

const int N = 15010, M = 32010;
int n;
int tr[M], level[N];

int lowbit(int x)
{
    return x & -x; 
}

// 单点修改
void add(int x, int d)
{
    for (int i = x; i < M; i += lowbit(i))
        tr[i] += d;
}

// 区间查询
int ask(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i ++)
    {
        int x, y; cin >> x >> y;
        x ++;
        // 统计1 ~ x中数的总和
        int t = ask(x);
        level[t] ++;
        add(x, 1);
    }

    for (int i = 0; i < n; i ++) 
        cout << level[i] << endl;
    return 0;
}
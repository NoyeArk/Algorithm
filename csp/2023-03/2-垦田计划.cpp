/**
 * @file 2-垦田计划.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-30
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  如果不投入任何资源，那么完成时间为最长的那一个
 *  1.每次投入耗时最长的任务中所需要的资源
 *  2.然后再从剩下的任务中选择耗时最长的继续投入资源
 *  3.一直循环，直到手中的资源不够继续投入
 *  
 *  ·如何选出耗时最长的任务？使用优先队列，默认按第一个元素排序
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Task
{
    int t, c;
    Task(int t, int c)
    {
        this->t = t;
        this->c = c;
    }
};

struct cmp
{
    bool operator () (const Task &a, const Task &b)		  
	{
		return a.t < b.t;	
	}
};

const int N = 100010;
int t[N], c[N];
int n, m, k;

priority_queue<Task, vector<Task>, cmp> q;

int schedule()
{
    int tmp = 0;  // 标识t到达k的个数
    while (q.size())
    {
        auto task = q.top(); q.pop();
        // printf("--%d %d %d--\n", task.t, task.c, task.cnt);
        if (task.t == k) 
        {
            if (++ tmp == n) return task.t;
            q.push(task);
            continue;
        }

        m -= task.c;

        if (m < 0) return task.t;
        task.t --;
        q.push(task);
        
        // cout << m << " " << tmp << endl;
    }
    return -1;
}

int main()
{
    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; i ++)
    {
        int t, c; cin >> t >> c;
        q.push(Task(t, c));
    }
    
    cout << schedule();
    return 0;
}
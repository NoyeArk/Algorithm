/**
 * @file BFS.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-24
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

queue<int> q;
st[1] = true;  // 表示1号点已经被遍历过
q.push(1);

while (q.size())
{
    int t = q.front();
    q.pop();

    for (int i = h[t]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            st[j] = true;  // 表示点j已经被遍历过
            q.push(j);
        }
    }
}
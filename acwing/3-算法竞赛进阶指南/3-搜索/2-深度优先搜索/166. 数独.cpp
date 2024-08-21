/**
 * @file 166. 数独.cpp
 * @author horiki
 * @date 2024-08-21
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 9, M = 1 << N;
int ones[M], logg[M];
int row[N], col[N], cell[3][3];
string str;

int lowbit(int x)
{
    return x & -x;
}

void init()
{
    for (int i = 0; i < N; i ++) row[i] = col[i] = cell[i / 3][i % 3] = M - 1;
}

void draw(int x, int y, int t)
{
    int s = 1;
    if (t > 0) str[x * N + y] = t;
    else s = -1, t = -t, str[x * N + y] = 0;
    t --;
    row[x] -= (1 << t) * s;
    col[x] -= (1 << t) * s;
    cell[x / 3][y / 3] -= (1 << t) * s;
}

int get(int x, int y)
{
    return row[x] & col[y] & cell[x / 3][y / 3];
}

bool dfs(int cnt)
{
    if (!cnt) return true;

    // 找出当前选择最小的位置进行填充
    int minv = 10, x, y;
    for(int i = 0; i < N; i ++)
        for (int j = 0; j < N; j ++)
            if (str[i * N + j] != '.') 
            {
                int t = ones[get(i, j)];
                if (t < minv) minv = t, x = i, y = j;
            }
    
    // 对[x, y]进行所有可能的填充
    for (int i = get(x, y); i; i -= lowbit(i))
    {
        int t = logg[lowbit(i)] + 1;
        draw(x, y, t);
        if (dfs(cnt - 1)) return true;
        draw(x, y, -t);
    }
    return false;
}

void work()
{
    init();

    int cnt = 0;
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < N; j ++)
        {
            char c = str[i * N + j];
            if (c != '.') draw(i, j, c - '1');
            else cnt ++;
        }
    dfs(cnt);
    cout << str << endl;
}

int main()
{
    for (int i = 0; i < N; i ++) logg[1 << i] = i;
    for (int i = 0; i < M; i ++)
        for (int j = i; j; j -= lowbit(j)) ones[i] ++;
    
    while (cin >> str, str != "end") work();
    return 0;
}
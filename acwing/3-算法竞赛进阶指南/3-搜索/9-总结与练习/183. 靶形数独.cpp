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
using namespace std;

const int N = 9, M = 1 << N;
int ones[M], map[M], g[N][N];
int row[N], col[N], cell[3][3];
int ans = -1;

int lowbit(int x)
{
    return x & -x;
}

void init()
{
    for (int i = 0; i < N; i ++) map[1 << i] = i;
    for (int i = 0; i < M; i ++)
        for (int j = i; j; j -= lowbit(j))
            ones[i] ++;
    for (int i = 0; i < N; i ++) row[i] = col[i] = cell[i / 3][i % 3] = M - 1;
}

void draw(int x, int y, int t)
{
    int s = 1;
    if (t > 0) g[x][y] = t;
    else s = -1, t = -t, g[x][y] = 0;
    t --;
    row[x] -= (1 << t) * s;
    col[y] -= (1 << t) * s;
    cell[x / 3][y / 3] -= (1 << t) * s;
}

int get_score(int x, int y, int t)
{
    return (min(min(x, 8 - x), min(y, 8 - y)) + 6) * t;
}

int get(int x, int y)
{
    return row[x] & col[y] & cell[x / 3][y / 3];
}

void dfs(int cnt, int score)
{
    if (!cnt) 
    {
        ans = max(ans, score);
        return ;
    }
    int minv = 10, x, y;
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < N; j ++)
            if (!g[i][j])
            {
                int t = ones[get(i, j)];
                if (t < minv)
                {
                    minv = ones[get(i, j)];
                    x = i, y = j;
                }
            }
    for (int i = get(x, y); i; i -= lowbit(i))
    {
        int t = map[lowbit(i)] + 1;
        draw(x, y, t);
        dfs(cnt - 1, score + get_score(x, y, t));
        draw(x, y, -t);
    }
}

int main()
{
    init();

    int cnt = 0, score = 0;
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < N; j ++)
        {
            int x; cin >> x;
            if (x)
            {
                draw(i, j, x);
                score += get_score(i, j, x);
            }
            else cnt ++;
        }
    dfs(cnt, score);

    cout << ans;
    return 0;
}
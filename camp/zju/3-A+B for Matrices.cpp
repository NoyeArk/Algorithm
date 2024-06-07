/**
 * @file 3-A+B for Matrices.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-07
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	暴力可以直接过，优化也可以直接过
 * 	题目链接：
 * 	https://www.nowcoder.com/practice/e431b3ae9efa4726b45a659b71abe124?tpId=63&tqId=29600&qru=/ta/zju-kaoyan/question-ranking
 */

#include <iostream>
using namespace std;

const int N = 25;
int n, m;
int A[N][N], B[N][N], C[N][N];

void input(int a[N][N]) 
{
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j];
}

int add() 
{
    bool st[N] = { false };
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            C[i][j] = A[i][j] + B[i][j];
            if (C[i][j])
            {
                // 第i行和第j列将不会成为最终答案
                st[i] = true, st[j + n] = true;
            }
        }
    int res = 0;
    for (int i = 1; i <= n + m; i ++)
        if (!st[i]) res ++;
    return res;
}

int main() 
{
    while (cin >> n >> m) 
    {
        if (n == 0) break;
        input(A);
        input(B);
        cout << add() << endl;
    }
}
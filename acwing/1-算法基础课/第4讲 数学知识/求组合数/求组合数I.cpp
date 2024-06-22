/**
 * @file 求组合数I.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-05
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  根据不同的数据范围使用不同的方法
 *  C(a, b) = a!/(b!*(a-b)!)
 *  将集合划分为：选第a个和不选第a个
 *  使用递推式:C(a, b) = C(a-1, b) + C(a-1, b-1)
 */

#include <iostream>
using namespace std;

const int N = 2010, mod = 1e9 + 7;
int c[N][N];

void init()
{
    for (int i = 0; i < N; i ++)
        for (int j = 0; j <= i; j ++)
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
}

int main()
{
    init();
    int n; cin >> n;
    while (n --)
    {
        int a, b; cin >> a >> b;
        cout << c[a][b] << endl;
    }
    return 0;
}
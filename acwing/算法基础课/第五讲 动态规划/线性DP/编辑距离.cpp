/**
 * @file 编辑距离.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-08
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010;
int n, m, f[N][N];
char a[N][12];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++)
        cin >> a[i] + 1;

    while (m --)
    {
        char tar[14]; 
        int cnt; cin >> tar + 1 >> cnt;

        int ans = 0;
        for (int k = 1; k <= n; k ++)
        {
            for (int i = 0; i <= strlen(tar + 1); i ++ ) f[0][i] = i;
            for (int i = 0; i <= strlen(a[k] + 1); i ++ ) f[i][0] = i;

            for (int i = 1; i <= strlen(a[k] + 1) ; i ++)
                for (int j = 1; j <= strlen(tar + 1); j ++)
                {
                    f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[k][i] != tar[j]));
                }
            if (f[strlen(a[k] + 1)][strlen(tar + 1)] <= cnt) ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}
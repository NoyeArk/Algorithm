/**
 * @file 蒙德里安的梦想.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-12
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  先放横着的，再放竖着的
 *  总方案数 = 只放横着小方块的合法方案数
 *  如何判断当前方案是否合法？
 *      所有剩余位置，能否填充满竖着的小方块，可以按列来看，每一列内部所有连续的
 *      空着的小方块，需要是偶数个
 *  1.状态表示：f[i, j]表示已经将前i-1列摆好，且从第i-1列，伸出到第i列的状态是j的所有方案
 *  2.状态计算：一般是依据最后一步的操作来进行分割
 *      最后一步的操作是枚举第i-1列和第i列哪些行放着1×2的方格
 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 12, M = 1 << N;
long long f[N][M];
bool st[M];
vector<int> state[M];

int main()
{
    int n, m;
    while (cin >> n >> m, n || m)
    {
        for (int i = 0; i < 1 << n; i ++)
        {
            int cnt = 0;
            bool is_valid = true;
            for (int j = 0; j < n; j ++)
            {
                if ((i >> j) & 1)
                {
                    if (cnt & 1) 
                    {
                        is_valid = false;
                        break;
                    }
                    else cnt = 0;
                }
                else cnt ++;
            }
            if (cnt & 1) is_valid = false;
            st[i] = is_valid;
        }

        for (int j = 0; j < (1 << n); j ++)
        {
            state[j].clear();
            for (int k = 0; k < (1 << n); k ++)
                if ((j & k) == 0 && st[j | k])
                    state[j].push_back(k);
        }

        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= m; i ++)
            for (int j = 0; j < (1 << n); j ++)
                for (auto k : state[j])
                    f[i][j] += f[i - 1][k];

        cout << f[m][0] << endl;
    }

    return 0;
}
/**
 * @file 5. 多重背包问题 II.cpp
 * @author horiki
 * @date 2024-08-20
 * 
 * @brief 
 *  将多重背包问题通过二进制优化转化为01背包问题
 */

#include <iostream>
#include <vector>
using namespace std;

const int N = 2010;
int f[N];
struct Good
{
    int v, w;
};
vector<Good> goods;

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        int v, w, s; cin >> v >> w >> s;
        for (int k = 1; k <= s; k *= 2)
        {
            s -= k;
            goods.push_back({v * k, w * k});
        }
        if (s >= 0) goods.push_back({v * s, w * s});
    }

    for (auto it : goods)
        for (int j = m; j >= it.v; j --)
            f[j] = max(f[j], f[j - it.v] + it.w);

    cout << f[m];
    return 0;
}
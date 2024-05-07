/**
 * @file 4-宝藏.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-07
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <unordered_map>
using namespace std;

struct Matrix
{
    int a, b, c, d;
};

const int N = 200010;
int n, m;
int hh = 1e5, tt = 1e5 - 1;
Matrix q[N];
unordered_map<int, int> h;

void print(ans x)
{
    cout << ans.a << " " << ans.b << " " << ans.c << " " << ans.d << endl;
}

Matrix mult(Matrix& x, Matrix& y)
{
    Matrix res;
    res.a = x.a * y.a + x.b * y.c;
    res.b = x.a * y.b + x.b * y.d;
    res.c = x.c * y.a + x.d * y.c;
    res.d = x.c * y.b + x.d * y.d;
    return res;
}

void query(int st, int ed)
{
    Matrix ans = {1, 1, 1, 1};
    for (int i = st; i <= ed; i ++)
    {
        print(i);
        ans = mult(ans, q[i]);
    }
    cout << ans.a << " " << ans.b << " " << ans.c << " " << ans.d << endl;
}



int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        int v, a, b, c, d; cin >> v >> a >> b >> c >> d;
        if (v == 1)
        {
            q[hh - 1] = {a, b, c, d};
            h[i] = -- hh;
        }
        else
        {
            q[tt + 1] = {a, b, c, d};
            h[i] = ++ tt;
        }
    }

    while (m --)
    {
        int v; cin >> v;
        if (v == 1)
        {
            int i, a, b, c, d; cin >> i >> a >> b >> c >> d;
            int id = h[i];
            q[id] = {a, b, c, d};
        }
        else
        {
            int l, r; cin >> l >> r;
            l = h[l], r = h[r];
            query(l, r);
        }
    }

    return 0;
}
/**
 * @file 4-玩偶购买.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-18
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

int n, x, y, a, b;

bool check(int mid)
{
    // 判断能否购买mid个玩偶
    int res = n;

    int child_num = b / x;
    // 只给妹妹买mid个就够了
    if (child_num >= mid) return res >= mid * y;

    // 给妹妹买了child_num个
    res -= child_num * y;
    mid -= child_num;

    // 还需要给姐姐买mid个
    // 姐姐最多买father_num个
    int father_num = min(a / x, child_num - 1);
    if (mid > father_num) return false;

    return res >= mid * y;
}

int main()
{
    int t; cin >> t;
    while (t --)
    {
        cin >> n >> x >> y >> a >> b;

        int l = 0, r = 1e9;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        if (!r) cout << -1 << endl;
        else cout << r << endl;
    }
    return 0;
}
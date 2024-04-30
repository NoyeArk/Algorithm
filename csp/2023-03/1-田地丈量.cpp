/**
 * @file 1-田地丈量.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-30
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  使用差分，快速修改某一区间的值：
 *      1.是某个田地的一部分则大于0
 *      2.否则小于等于0
 *  上面这种方法不对，因为坐标可能是负数，观察到n<=100，可以考虑遍历田地
 *  问题在于：如何快速判断两个田地是否有交集？
 *  最终方法：直接遍历每一个田地，然后判断田地和(a, b)之间是否有交集，如果有就加上这个面积。
 */

#include <iostream>
using namespace std;

int main()
{
    int n, a, b; cin >> n >> a >> b;

    int ans = 0;
    while (n --)
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int w1 = max(x1, 0), w2 = min(x2, a);
        int h1 = max(y1, 0), h2 = min(y2, b);
        if (w1 >= w2 || h1 >= h2) continue;
        ans += (h2 - h1) * (w2 - w1);
    }

    cout << ans;
    return 0;
}
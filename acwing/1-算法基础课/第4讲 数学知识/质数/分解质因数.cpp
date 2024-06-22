/**
 * @file 分解质因数.cpp
 * @author horiki
 * @version 0.2
 * @date 2024-04-28 2024-05-09
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *      从小到大枚举所有数，n中最多只包含一个大于sqrt(n)的质因子
 *      时间复杂度：O(logn)~O(sqrt(n))
 */

#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    while (n --)
    {
        int x; cin >> x;
        for (int i = 2; i <= x / i; i ++)
        {
            int cnt = 0;
            if (x % i == 0)
            {
                while (x % i == 0)
                    x /= i, cnt ++;
                cout << i << " " << cnt << endl;
            }
        }
        if (x > 1) printf("%d 1\n", x);
        cout << endl;
    }
    return 0;
}
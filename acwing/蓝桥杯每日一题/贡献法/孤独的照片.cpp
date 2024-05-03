/**
 * @file 孤独的照片.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-03
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  判断每一个牛对于最终答案的贡献
 */

#include <iostream>
using namespace std;

typedef long long LL;

const int N = 500010;
char a[N];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    LL ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        LL l = 0, r = 0;
        for (int pl = i - 1; pl > 0; pl--)
            if (a[pl] != a[i]) l ++;
            else break;
            
        for (int pr = i + 1; pr <= n; pr++)
            if (a[pr] != a[i]) r ++;
            else break;
        ans += l * r + max(l - 1, (LL)0) + max(r - 1, (LL)0);
    }
    cout << ans;
    return 0;
}
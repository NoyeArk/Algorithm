/**
 * @file 100. IncDec序列.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-11
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  使用差分处理之后，相当于每次选择两个位置，一个位置+1，另一个位置-1
 *  进行上述操作直到没有正数或者没有负数，这时候还需要进行|pos - neg|次操作
 *  ----------------------
 *  为什么一开始没有做出来？
 *  题意就理解错误了，差分处理之后应该找整数和负数的次数，而我就只是找不为0的位置
 *  经验：应该认真思考每个知识点的性质，正确利用才能正确做题
 */

#include <iostream>
using namespace std;

typedef long long LL;

const int N = 100010;
LL a[N];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = n; i; i --) a[i] -= a[i - 1];
    
    LL pos = 0, neg = 0;
    for (int i =2; i <= n; i ++)
        if (a[i] > 0) pos += a[i];
        else neg -= a[i];
        
    cout << min(pos, neg) + abs(pos - neg) << endl;
    cout << abs(pos - neg) + 1;
    return 0;
}
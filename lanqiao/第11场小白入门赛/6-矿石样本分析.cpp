/**
 * @file 6-矿石样本分析.cpp
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

const int N = 200010;
int a[N];

int main()
{
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    int i = 1, j = n;
    while (i <= j)
    {
        if (a[i] + a[j] == k) break;
        else if (a[i] + a[j] > k) j --;
        else i ++;
    }
    
    if (i > j) cout << -1;
    else cout << max(min(i, n - i + 1), min(j, n - j + 1)) << endl;
	
    return 0;
}
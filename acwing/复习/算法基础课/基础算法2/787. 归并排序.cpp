/**
 * @file 787. 归并排序.cpp
 * @author horiki
 * @date 2024-09-20
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 100010;
int n, a[N];

void sort(int l, int r)
{
    if (l >= r) return ;
    int mid = l + r >> 1;
    sort(l, mid); sort(mid + 1, r);
    
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(1, n);

    return 0;
}
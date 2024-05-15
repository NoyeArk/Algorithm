/**
 * @file 1-快速排序.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-15
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

int a[] = {5, 2, 1, 0 ,9};

void quick_sort(int l, int r)
{
    if (l >= r) return ;

    int k = a[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j)
    {
        do i ++; while (a[i] < k);
        do j --; while (a[j] > k);
        if (i < j) swap(a[i], a[j]);
    }
    quick_sort(l, i);
    quick_sort(i + 1, r);
}

int main()
{
    quick_sort(0, 4);
    for (int i = 0; i <= 4; i ++) cout << a[i] << " ";
    return 0;
}
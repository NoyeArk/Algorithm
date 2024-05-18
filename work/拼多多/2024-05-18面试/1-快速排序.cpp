/**
 * @file 1-快速排序.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-18
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	快速排序真的好容易被考到
 */

#include <iostream>
using namespace std;

int a[] = {9, -1, 0, 3, 5, 2};

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
    quick_sort(l, j);
    quick_sort(j + 1, r);
}

int main()
{
    quick_sort(0, 5);
    for (int i = 0; i <= 5; i ++) 
        cout << a[i] << " ";
    return 0;
}
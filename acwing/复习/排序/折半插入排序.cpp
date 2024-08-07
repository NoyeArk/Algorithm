/**
 * @file 折半插入排序.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-07
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 100010;
int n;
int a[N];

void sort()
{
    for (int i = 2; i <= n; i ++)
    {
        int val = a[i];
        int l = 1, r = i;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (a[mid] <= val) l = mid + 1;
            else r = mid;
        }
        for (int j = i; j > r; j --) a[j] = a[j - 1];
        a[r] = val;
    }
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];

    sort();

	for (int i = 1; i <= n; i ++) cout << a[i] << " ";
	return 0;
}
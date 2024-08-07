/**
 * @file 插入排序.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-07
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

const int N = 100010;
int n;
int a[N];
vector<int> q[10];

void sort()
{
    int mx = a[1];
    for (int i = 2; i <= n; i ++)
        mx = max(mx, a[i]);
    int len = to_string(mx).size();
    int k = 1;
    while (len --)
    {
        for (int i = 1; i <= n; i ++)
        {
            int t = a[i] / k % 10;
            q[t].push_back(a[i]);
        }
        int cnt = 1;
        for (int i = 0; i < 10; i ++)
        {
            for (auto x : q[i]) a[cnt ++] = x;
            q[i].clear();
        }
        k *= 10;
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
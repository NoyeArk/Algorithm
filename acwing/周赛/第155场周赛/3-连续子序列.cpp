/**
 * @file 3-连续子序列.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-01
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	暴力做法：能过12个测试点
 * 	-----------------------
 * 	枚举右端点，用串来维护，因为串可以很方便对问题进行分类
 * 	分类的过程很像数位统计DP
 * 	从最高位开始，跟右端点异或和k相同的放左边，反之放右边
 * 	从最高位开始，每次可以分两类
 * 	为什么用串来进行分类：每一类对应一个分支，
 * 	遇到1：左边不能要
 * 	遇到0：左边全加上
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int N = 1000010;
int a[N], pre[N];

int main()
{
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i ++) 
	{
		cin >> a[i];
		pre[i] = pre[i - 1] ^ a[i];
	}

    int ans = 0;
	for (int len = 1; len <= n; len ++)
	    for (int i = 1; i + len - 1 <= n; i ++)
	    {
	        int j = i + len - 1;
	        if ((pre[j] ^ pre[i - 1]) >= k)
	            ans ++;
	    }
    
    cout << ans;
	return 0;
}
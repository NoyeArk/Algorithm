/**
 * @file 136. 邻值查找.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-07-31
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	求离我最近的一个数的值以及这个数所在数组中的下标
 * 	如果直接暴力求解，肯定超时，考试的时候如果没有其他思路只有这么做
 * 	但是这道题正确的解题方法是什么？真的完全没有思路
 * 	方法1：使用set
 * 	方法2：使用链表
 * 		首先把链表进行排序，然后先对第n个数进行处理，这样每个元素都在n的前面
 * 		之后把第n个数从链表中进行删除，再处理第n-1个数，这样当前链表中剩下的每个数都在n-1的前面
 * 		以此类推，求出所有答案
 * 	思考：为什么一开始没有任何思路？
 * 		以后遇到这种需要从前i-1个元素中选择的问题，可以考虑这种做法，先处理最后一个元素
 * 		这样剩下的肯定满足在i-1个元素中进行选择
 */

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<LL, int> PII;

const int N = 100010;
PII a[N], ans[N];
int p[N], l[N], r[N];

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a + 1, a + 1 + n);

	a[0].first = -4e9, a[n + 1].first = 4e9;
	for (int i = 1; i <= n; i ++)
	{
		l[i] = i - 1, r[i] = i + 1;
		p[a[i].second] = i;
	}
	
	for (int i = n; i > 1; i --)
	{
		int j = p[i], left = l[j], right = r[j];
		LL lval = abs(a[j].first - a[left].first);
		LL rval = abs(a[j].first - a[right].first);
		if (lval <= rval) ans[i] = {lval, a[left].second};
		else ans[i] = {rval, a[right].second};
		
		r[left] = right, l[right] = left;
	}

	for (int i = 2; i <= n; i ++)
		cout << ans[i].first << " " << ans[i].second << endl;

	return 0;
}
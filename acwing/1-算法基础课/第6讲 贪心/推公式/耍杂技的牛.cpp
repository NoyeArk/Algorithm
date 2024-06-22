/**
 * @file 耍杂技的牛.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-17
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 		2
 *   10   5
 * 	按上述方式排列：
 * 		10的奶牛风险值为1
 * 		5 的奶牛风险值为1
 * 		2 的奶牛风险值为0
 *  不是像金字塔一样叠啊，是垂直叠罗汉，一定要认真读题！
 * ------------------------------------------------
 * 	考虑在最终结果中，将第i头牛和i+1头牛交换会有什么影响？
 * 					交换前 						交换后
 * 	i		w1 + ... + wi-1 - si 			w1 + ... + wi-1 + wi+1 - si
 * 	i + 1   w1 + ... + wi-1 + wi - si+1		w1 + ... + wi-1 - si+1
 * 								||
 * 					交换前 						交换后
 * 	i		 		- si 					wi+1 - si
 * 	i + 1   		wi - si+1				- si+1
 * 	
 * 	wi - si+1 > wi+1 - si 满足这个条件一定会使交换前的风险大于交换后的风险，所以要进行交换
 * 	-> wi + si > wi+1 + si+1 将所有的牛按照wi+si升序排序，相加得到答案
 */

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 50010;
int w[N], s[N];
PII a[N];

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> w[i] >> s[i];
		a[i].first = w[i] + s[i];
		a[i].second = i;
	}

	sort(a + 1, a + 1 + n);

	int ans = -2e9, sum_w = 0;
	for (int i = 1; i <= n; i ++)
	{
		int id = a[i].second;
		ans = max(ans, sum_w - s[id]);
		sum_w += w[id];
	}

	cout << ans;
	return 0;
}
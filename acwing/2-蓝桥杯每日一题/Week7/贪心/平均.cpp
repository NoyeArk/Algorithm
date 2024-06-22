/**
 * @file 平均.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-04
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	将每个数字的所有代价从小到大进行排序，然后根据需要删除的个数，每次选择代价最小的进行相加
 * 	时间复杂度：O(2n)
 * 	运行时间：720ms 运行空间：4056KB
 */

#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

const int N = 100010;
int a[N], b[N];

vector<int> nums[N];

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		int a, b; cin >> a >> b;
		nums[a].push_back(b);
	}

	for (int i = 0; i <= 9; i ++)
		sort(nums[i].begin(), nums[i].end());

	LL cnt = n / 10, ans = 0;

	for (int i = 0; i <= 9; i ++)
	{
		int diff = nums[i].size() - cnt;
		for (int j = 0; j < diff; j ++)
			ans += nums[i][j];
	}

	cout << ans;
	return 0;
}
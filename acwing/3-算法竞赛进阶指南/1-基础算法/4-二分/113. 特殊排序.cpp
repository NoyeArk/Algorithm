/**
 * @file 113. 特殊排序.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-07-28
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  找到数组中第一个大于x的元素的位置，即
 *      如果 i <= a[mid]，则 l = mid + 1
 *      如果 i > a[mid]，则 r = mid
 */

class Solution {
public:
    vector<int> specialSort(int N) {
        vector<int> ans = {1};
        
        for (int i = 2; i <= N; i ++)
		{
			int l = 0, r = ans.size() - 1;
			while (l < r)
			{
				int mid = l + r >> 1;
				if (compare(i, ans[mid])) r = mid;
				else l = mid + 1;
			}
            if (compare(i, ans[r])) ans.insert(ans.begin() + r, i);
            else ans.insert(ans.begin() + r + 1, i);
		}
		return ans;
    }
};
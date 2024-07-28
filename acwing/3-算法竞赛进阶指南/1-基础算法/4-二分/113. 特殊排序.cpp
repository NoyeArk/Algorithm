/**
 * @file 113. 特殊排序.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-07-28
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

class Solution {
public:
    vector<int> specialSort(int N) {
        vector<int> ans;
        
        for (int i = 1; i <= N; i ++)
		{
			int l = 0, r = ans.size() - 1;
			while (l < r)
			{
				int mid = l + r + 1 >> 1;
				if (compare(mid, i)) l = mid;
				else r = mid - 1;
			}
			ans.insert(ans.begin() + r, i);
		}

		return ans;
    }
};
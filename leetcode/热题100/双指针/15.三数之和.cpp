/**
 * @file 15.三数之和.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-04
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  观察到数组的顺序对结果没有影响，所以可以先进行排序
 *  因为和为0，所以三个数中肯定有正有负，所以应该使用对撞指针
 * 	
 * 	时间复杂度：O(n²) 空间复杂度：O(n)
 */

class Solution {
public:
    bool st[200010];

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i ++)
        {
            int sum = 0 - nums[i];

            int tmp = sum + 100000;
            if (st[tmp]) continue;
            st[tmp] = true;

            int l = 0, r = nums.size() - 1;
            while (l < r)
            {
                if (l == i) l ++;
                else if (r == i) r --;
                else if (nums[l] + nums[r] < sum) l ++;
                else if (nums[l] + nums[r] > sum) r --;
                else if (nums[l] + nums[r] == sum)
                {
                    vector<int> tmp = {nums[i], nums[l], nums[r]};
                    sort(tmp.begin(), tmp.end());
                    res.push_back(tmp);
                    l ++, r --;
                }
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
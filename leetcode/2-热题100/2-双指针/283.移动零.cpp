/**
 * @file 283.移动零.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-03
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	时间复杂度：O(n)
 * 	空间复杂度：O(1) 没有开辟额外的空间
 */

class Solution {
public:
    bool st[10010];

    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i ++)
            if (!nums[i]) st[i] = true;

        int i = 0;
        for (int j = 0; j < n; j ++)
            if (!st[j]) nums[i ++] = nums[j];
        while (i < n) nums[i ++] = 0;
    }
};
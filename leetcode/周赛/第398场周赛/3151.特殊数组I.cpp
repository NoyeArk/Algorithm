/**
 * @file 3151.特殊数组I.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-25
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i ++)
            if ((nums[i] + nums[i - 1]) % 2 == 0)
                return false;
        return true;
    }
};
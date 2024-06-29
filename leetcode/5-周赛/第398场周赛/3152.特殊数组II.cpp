/**
 * @file 3152.特殊数组II.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-25
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	直接判断会TLE，可以考虑先预处理出来答案
 * 	使用前缀和预处理出来所有的结果，判断每一个元素和它前面的元素奇偶性是否不同
 *  不同为0 相同为1
 *  最后使用O(1)查询结果
 */

class Solution {
public:
    int pre[100010];

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;

        pre[0] = 0;
		for (int i = 1; i < nums.size(); i ++)
            if ((nums[i] + nums[i - 1]) % 2 == 0)
                pre[i + 1] = 1;

        for (int i = 0; i < nums.size(); i ++)
            pre[i + 1] += pre[i];

        for (int i = 1; i <= nums.size(); i ++)
            cout << pre[i] << " ";
        
        for (auto q : queries)
        {
            int l = q[0], r = q[1];
            int tmp = pre[r + 1] - pre[l + 1];
            if (tmp) ans.push_back(false);
            else ans.push_back(true);
        }
		
		return ans;
    }
};
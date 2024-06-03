/*
时间复杂度:
    双指针：O(nlogn)
    哈希表：O(n)
空间复杂度:
    双指针：O(n)
    哈希表：O(n)
*/

class Solution {
public:
    // 法1：双指针
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tmp, ans;
        tmp = nums; 
        int n = nums.size();
        sort(tmp.begin(), tmp.end());

        int l = 0, r = n - 1;
        while (l < r)
        {
            if (tmp[l] + tmp[r] == target) break;
            else if (tmp[l] + tmp[r] > target) r --;
            else l ++;
        }

        // 寻找下标
        for (int i = 0; i < n; i ++)
        {
            if (tmp[l] == nums[i]) 
            {
                ans.push_back(i);
                break;
            }
        }
        for (int i = n - 1; i >= 0; i --)
        {
            if (tmp[r] == nums[i]) 
            {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }

    // 法2：哈希表
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i ++)
        {
            auto it = hash.find(target - nums[i]);
            if (it != hash.end()) return {it->second, i};
            else hash[nums[i]] = i;
        }
        return {};
    }
};

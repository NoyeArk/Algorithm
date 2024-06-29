/**
 * @file 11.盛最多水的容器.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-03
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  让围成的矩形面积最大，是否可以考虑枚举区间长度
 *  暴力做法：两重循环，枚举所有区间，会超时，跑过55/62个样例
 * 
 * 	本题做法是对撞指针，双指针的类型：
 * 		1、快慢指针：从同一侧开始遍历
 * 		2、对撞指针：从两侧向中间开始遍历，例如判断回文串
 * 	时间复杂度：O(n)
 * 	空间复杂度：O(1)
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        // ---------------暴力做法-----------------
        // for (int i = 0; i < n; i ++)
        //     for (int j = i + 1; j < n; j ++)
        //     {
        //         int len = j - i;
        //         ans = max(ans, len * min(height[i], height[j]));
        //     }

        int ans = 0;
        int l = 0, r = n - 1;
        while (l < r)
        {
            ans = max(ans, (r - l) * min(height[l], height[r]));
            if (height[l] <= height[r]) l ++;
            else r --;
        }
        return ans;
    }
};
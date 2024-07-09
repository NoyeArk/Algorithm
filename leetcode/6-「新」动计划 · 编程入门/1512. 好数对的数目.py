'''
 @file 1512. 好数对的数目.py
 @author horiki
 @version 0.1
 @date 2024-07-09
 @copyright Copyright (c) 2024
 
 @brief 
 
'''

# 解法1：暴力枚举
from typing import List

class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        cnt = 0
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] == nums[j]:
                    cnt += 1
        return cnt
    
# 解法2：哈希表
import collections
from typing import List

class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        m = collections.Counter(nums)
        return sum(v * (v - 1) // 2 for k, v in m.items())
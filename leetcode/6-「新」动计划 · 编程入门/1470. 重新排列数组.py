'''
 @file 1470. 重新排列数组.py
 @author horiki
 @version 0.1
 @date 2024-07-19
 @copyright Copyright (c) 2024
 
 @brief 
 
'''

# 解法1 
class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        ans = []
        for i in range(n):
            ans += [nums[i], nums[i + n]]
        return ans
    
# 解法2
class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        nums[::2], nums[1::2] = nums[:n], nums[n:]
        return nums
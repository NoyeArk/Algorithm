'''
 @file 852. 山脉数组的峰顶索引.py
 @author 弘树
 @version 0.1
 @date 2024-07-23
 @copyright Copyright (c) 2024
 
 @brief 
 
'''

# 二分查找
class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        l, r = 0, len(arr) - 1
        while l < r:
            mid = (l + r) // 2
            if arr[mid] < arr[mid + 1]:
                l = mid + 1
            else:
                r = mid
        return r
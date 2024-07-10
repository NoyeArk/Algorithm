'''
 @file 1534. 统计好三元组.py
 @author horiki
 @version 0.1
 @date 2024-07-10
 @copyright Copyright (c) 2024
 
 @brief 
 
'''
 
# 暴力枚举
class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        ans = 0
        for i in range(len(arr)):
            for j in range(i + 1, len(arr)):
                for k in range(j + 1, len(arr)):
                    if abs(arr[i] - arr[j]) <= a and abs(arr[j] - arr[k]) <= b and abs(arr[i] - arr[k]) <= c:
                        ans += 1
        return ans
'''
 @file 1486. 数组异或操作.py
 @author horiki
 @version 0.1
 @date 2024-07-08
 @copyright Copyright (c) 2024
 
 @brief 
 
'''
 
class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        ans = 0
        for i in range(n):
            ans ^= start + 2 * i
        return ans
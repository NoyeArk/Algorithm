'''
 @file 231. 2 的幂.py
 @author horiki
 @version 0.1
 @date 2024-07-16
 @copyright Copyright (c) 2024
 
 @brief 
 
'''

# 解法1
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 0:
            return False
        cnt = 0
        while n:
            cnt += n & 1
            if cnt > 1:
                return False
            n >>= 1
        return True


# 解法2
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n > 0 and n & (n - 1) == 0
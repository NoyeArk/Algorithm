'''
 @file 326. 3 的幂.py
 @author horiki
 @version 0.1
 @date 2024-07-17
 @copyright Copyright (c) 2024
 
 @brief 
 
'''

# 试除法1
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        while n >= 3:
            r, n = n % 3, n // 3
            if r:
                return False
        return n == 1

# 试除法2
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n <= 0:
            return False
        while n % 3 == 0:
            n //= 3
        return n == 1

# 判断是否为最大 3 的幂的约数
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        return n > 0 and 1162261467 % n == 0
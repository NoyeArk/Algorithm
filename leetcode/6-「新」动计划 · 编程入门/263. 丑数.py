'''
 @file 263. 丑数.py
 @author horiki
 @version 0.1
 @date 2024-07-18
 @copyright Copyright (c) 2024
 
 @brief 
 
'''
 
class Solution:
    def isUgly(self, n: int) -> bool:
        divisors = [2, 3, 5]
        for i in divisors:
            while n and n % i == 0:
                n //= i
        return n == 1
'''
 @file 258. 各位相加.py
 @author horiki
 @version 0.1
 @date 2024-07-14
 @copyright Copyright (c) 2024
 
 @brief 
 
'''
 
class Solution:
    def addDigits(self, num: int) -> int:
        if num < 10:
            return num
        res = 0
        while num:
            res += num % 10
            num //= 10
        return self.addDigits(res)
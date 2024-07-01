'''
 @file 2413. 最小偶倍数.py
 @author horiki
 @version 0.1
 @date 2024-07-01
 @copyright Copyright (c) 2024
 
 @brief 
 
'''
 
class Solution:
    def smallestEvenMultiple(self, n: int) -> int:
        return (n % 2 + 1) * n
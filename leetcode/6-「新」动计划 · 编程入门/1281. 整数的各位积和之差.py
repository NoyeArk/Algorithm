'''
 @file 1281. 整数的各位积和之差.py
 @author horiki
 @version 0.1
 @date 2024-07-15
 @copyright Copyright (c) 2024
 
 @brief 
 
'''
 
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        mult, sum = 1, 0
        while n > 0:
            mult *= n % 10
            sum += n % 10
            n //= 10
        return mult - sum
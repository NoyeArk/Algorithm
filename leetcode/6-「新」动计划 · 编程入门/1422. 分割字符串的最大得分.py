'''
 @file 1422. 分割字符串的最大得分.py
 @author 弘树
 @version 0.1
 @date 2024-07-21
 @copyright Copyright (c) 2024
 
 @brief 
 
'''

# 解法1：模拟
class Solution:
    def maxScore(self, s: str) -> int:
        cnt_one = 0
        for i in range(len(s)):
            if s[i] == '1':
                cnt_one += 1

        ans, sum = 0, 0
        for i in range(len(s) - 1):
            if s[i] == '1':
                sum += 1
            # 左边0的个数为i-sum 右边1的个数为
            ans = max(ans, i + 1 - sum + cnt_one - sum)
        
        return ans

# 解法2：列表表达式
class Solution:
    def maxScore(self, s: str) -> int:
        return max(s[:i].count('0') + s[i:].count('1') for i in range(1, len(s)))
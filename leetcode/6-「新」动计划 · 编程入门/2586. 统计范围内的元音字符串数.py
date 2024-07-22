'''
 @file 2586. 统计范围内的元音字符串数.py
 @author 弘树
 @version 0.1
 @date 2024-07-22
 @copyright Copyright (c) 2024
 
 @brief 
 
'''

#解法1
class Solution:
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        ans = 0
        for i in range(left, right + 1):
            if words[i][0] in "aeiou" and words[i][-1] in "aeiou":
                ans += 1
        return ans

# 解法2
class Solution:
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        return sum(1 for i in range(left, right + 1) if words[i][0] in "aeiou" and words[i][-1] in "aeiou")
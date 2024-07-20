'''
 @file 867. 转置矩阵.md
 @author 弘树
 @version 0.1
 @date 2024-07-20
 @copyright Copyright (c) 2024
 
 @brief 
 
'''
 
class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        import numpy as np
        return np.transpose(matrix).tolist()
'''
 @file 2469. 温度转换.py
 @author horiki
 @version 0.1
 @date 2024-06-30
 @copyright Copyright (c) 2024
 
 @brief 
 
'''
 
class Solution:
    def convertTemperature(self, celsius: float) -> List[float]:
        return [celsius + 273.15, celsius * 1.8 + 32]
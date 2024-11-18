'''
 @file BMN1 小红的新周赛.py
 @author 弘树
 @date 2024-11-18
 
 @brief 
 
'''

# 解法一
a = input().split()
a = [int(x) for x in a]
print(sum(a))


# 解法二
print(sum(list(map(int, input().split()))))
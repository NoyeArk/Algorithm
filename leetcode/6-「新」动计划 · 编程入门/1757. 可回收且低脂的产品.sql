'''
 @file 1757. 可回收且低脂的产品.sql
 @author horiki
 @version 0.1
 @date 2024-07-12
 @copyright Copyright (c) 2024
 
 @brief 
 
'''

select product_id from Products where low_fats = 'Y' and recyclable = 'Y';
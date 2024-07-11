'''
 @file 584. 寻找用户推荐人.sql
 @author horiki
 @version 0.1
 @date 2024-07-11
 @copyright Copyright (c) 2024
 
 @brief 
 
'''

select name from Customer where referee_id <> 2 or referee_id is null;
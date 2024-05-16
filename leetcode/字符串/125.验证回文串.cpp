/**
 * @file 125.验证回文串.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-16
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	遇到问题一定要理清思路，加油 horiki
 */

class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        // 字符串清洗
        for (int i = 0; i < s.size(); i ++)
        {
            // 小写字母
            if (s[i] >= 'a' && s[i] <= 'z')
                str += s[i];
            // 大写字母
            else if (s[i] >= 'A' && s[i] <= 'Z')
                str += s[i] + ('a' - 'A');
            // 数字
            else if (s[i] >= '0' && s[i] <= '9')
                str += s[i];
        }
        if (!str.size()) return true;
        // 判断回文串
        int l = 0, r = str.size() - 1;
        while (l <= r)
            if (str[l] == str[r])
                l ++, r --;
            else break;
        return l >= r;
    }
};
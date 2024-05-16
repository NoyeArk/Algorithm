/**
 * @file 520.检测大写字母.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-16
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	遇到一个问题，不要想的太复杂，怎么简单怎么来
 */

class Solution {
public:
    bool detectCapitalUse(string word) {
        vector<int> id;
        for (int i = 0; i < word.size(); i ++)
            if (word[i] >= 'A' && word[i] <= 'Z') 
                id.push_back(i);

        // 情况1
        if (id.size() == word.size()) return true;
        // 情况2
        if (id.size() == 0) return true;
        // 情况3
        if (id.size() == 1 && id[0] == 0) return true;
        return false;
    }
};
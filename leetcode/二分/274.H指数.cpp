/**
 * @file 274.H指数.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-30
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

class Solution {
public:
    bool check(vector<int>& citations, int mid)
    {
        int id = lower_bound(citations.begin(), citations.end(), mid) - citations.begin();
        if (citations.size() - id >= mid) return true;
        else return false;
    }

    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int l = 0, r = 1000;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (check(citations, mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
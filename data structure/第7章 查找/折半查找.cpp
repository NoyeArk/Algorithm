/**
 * @file 折半查找.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-21
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

bool check(int mid)
{
	// todo
}

// 将区间[l, r]划分成[l, mid]和[mid + 1, r]，mid不需要加1
int binary_search_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

// 将区间[l, r]划分成[l, mid - 1]和[mid, r]，mid需要加1
int binary_search_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
/**
 * @file 区间分组.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-13
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  1.将所有区间按左端点从小到大排序
 *  2.从前往后处理每个区间
 *      判断能否将其放到某个现有的组中
 */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
PII q[N];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> q[i].first >> q[i].second;
    sort(q + 1, q + 1 + n);

    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 1; i <= n; i ++)
    {
        auto [l, r] = q[i];
        if (heap.empty() || heap.top() >= l)
            heap.push(r);
        else
        {
            heap.pop();
            heap.push(r);
        }

        // auto [left, right] = q[i];
        // // 二分查找
        // int l = 0, r = interval.size() - 1;
        // while (l < r)
        // {
        //     int mid = l + r >> 1;
        //     if (interval[mid].second < left) r = mid;
        //     else l = mid + 1;
        // }
        // if (r < 0 || interval[r].second >= left)
        //     interval.push_back(q[i]);
        // else interval[r].second = right;

        // printf("r:%d cnt:%d\n", r, interval.size());
    }
    cout << heap.size();
    return 0;
}
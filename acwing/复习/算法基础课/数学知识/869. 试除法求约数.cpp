/**
 * @file 869. 试除法求约数.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    while (n --)
    {
        int x; cin >> x;
        vector<int> ans;
        for (int i = 1; i <= x / i; i ++)
            if (x % i == 0)
            {
                ans.push_back(i);
                if (i != x / i) ans.push_back(x / i);
            }
        sort(ans.begin(), ans.end());
        for (auto t : ans) cout << t << " ";
        cout << endl;
    }

    return 0;
}
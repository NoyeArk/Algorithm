/**
 * @file 869. 试除法求约数 2.cpp
 * @author horiki
 * @date 2024-08-26
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
        if (x) ans.push_back(x);
        sort(ans.begin(), ans.end());
        for (auto val : ans) cout << val << " ";
        cout << endl;
    }

    return 0;
}